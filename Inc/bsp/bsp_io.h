#ifndef __BSP_IO_H_
#define __BSP_IO_H_

#include "bluenrg_lpx.h"
#include "rf_driver_ll_bus.h"


//USART1 TX PORT CONFIG
#define BSP_UART_TX_GPIO_CLK_ENABLE()					LL_AHB_EnableClock(LL_AHB_PERIPH_GPIOA)

void BSP_IO_Init(void);
void BSP_COM_Init(void);
#endif /* __BSP_IO_H_ */
