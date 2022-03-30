#include <stdio.h>

#include "rf_driver_ll_usart.h"

#include "lp_uart.h"
#include "bsp_io.h"

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
