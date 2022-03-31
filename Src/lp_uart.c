#include <stdio.h>

#include "rf_driver_ll_usart.h"

#include "lp_uart.h"
#include "bsp_io.h"

#define UART_RECV_BUFFER_LEN     40
#define UART_SEND_BUFFER_LEN     40

uint8_t uRecvBuffer[UART_RECV_BUFFER_LEN];
uint8_t uRecvLen = 0;

uint8_t uSendBuffer[UART_SEND_BUFFER_LEN];
uint8_t uSendLen = 0;


void BSP_COM_IRQHandler(void)
{
	uint8_t read_data;
	
	/* If the RX FIFO is Not Empty */
	if (LL_USART_IsActiveFlag_RXNE(BSP_UART)) {
		
    /* Read a byte from the RX FIFO */
    read_data = LL_USART_ReceiveData8(BSP_UART);
		
		/* Wait for TX FIFO not full flag to be raised */
    while (LL_USART_IsActiveFlag_TXE(BSP_UART) == 0);

    /* Send the byte to the UART */
    LL_USART_TransmitData8(BSP_UART, read_data);
	}
}




/* keil debug port defines */
#define ITM_Port8(n)    (*((volatile unsigned char *)(0xE0000000+4*n)))
#define ITM_Port16(n)   (*((volatile unsigned short*)(0xE0000000+4*n)))
#define ITM_Port32(n)   (*((volatile unsigned long *)(0xE0000000+4*n)))
#define DEMCR           (*((volatile unsigned long *)(0xE000EDFC)))
#define TRCENA          0x01000000

struct __FILE { int handle; /* Add whatever needed */ };
FILE __stdout;
FILE __stdin;

int fputc(int c, FILE *f)
{  

  /* Wait for TX FIFO not full flag to be raised */
    while (LL_USART_IsActiveFlag_TXE(BSP_UART) == 0);

    /* Send the byte to the UART */
    LL_USART_TransmitData8(BSP_UART, (uint8_t)c);

  return 1;
}
