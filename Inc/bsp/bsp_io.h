#ifndef __BSP_IO_H_
#define __BSP_IO_H_

#include "bluenrg_lpx.h"

#include "rf_driver_ll_bus.h"
#include "rf_driver_ll_gpio.h"

#define BSP_IRQ_HIGH_PRIORITY                         1

#define BSP_UART                                  USART1
#define BSP_UART_IRQn                             USART1_IRQn
#ifndef BSP_UART_BAUDRATE
#define BSP_UART_BAUDRATE                         (115200)
#endif /*BSP_UART_BAUDRATE*/
#define BSP_UART_CLK_ENABLE()                     LL_APB1_EnableClock(LL_APB1_PERIPH_USART)
#define BSP_UART_CLK_DISABLE()                    LL_APB1_DisableClock(LL_APB1_PERIPH_USART)
#define BSP_UART_GPIO_CLOCK_ENABLE()              LL_AHB_EnableClock(LL_AHB_PERIPH_GPIOA)
#define BSP_UART_GPIO_CLOCK_DISABLE()             LL_AHB_DisableClock(LL_AHB_PERIPH_GPIOA)

//USART1 TX PORT CONFIG
#define BSP_UART_TX_PIN                           LL_GPIO_PIN_9
#define BSP_UART_TX_GPIO_PORT                     GPIOA
#define BSP_UART_TX_GPIO_AF_N                     LL_GPIO_AF_0
#define BSP_UART_TX_GPIO_AF()                     LL_GPIO_SetAFPin_8_15(GPIOA, LL_GPIO_PIN_9, LL_GPIO_AF_0)
#define BSP_UART_TX_GPIO_CLK_ENABLE()             LL_AHB_EnableClock(LL_AHB_PERIPH_GPIOA)
#define BSP_UART_TX_GPIO_CLK_DISABLE()            LL_AHB_DisableClock(LL_AHB_PERIPH_GPIOA)

//USART1 RX PORT CONFIG
#define BSP_UART_RX_PIN                           LL_GPIO_PIN_8
#define BSP_UART_RX_GPIO_PORT                     GPIOA
#define BSP_UART_RX_GPIO_AF_N                     LL_GPIO_AF_0
#define BSP_UART_RX_GPIO_AF()                     LL_GPIO_SetAFPin_8_15(GPIOA, LL_GPIO_PIN_8, LL_GPIO_AF_0)
#define BSP_UART_RX_GPIO_CLK_ENABLE()             LL_AHB_EnableClock(LL_AHB_PERIPH_GPIOA)
#define BSP_UART_RX_GPIO_CLK_DISABLE()            LL_AHB_DisableClock(LL_AHB_PERIPH_GPIOA)



void BSP_IO_Init(void);
void BSP_COM_Init(void);
#endif /* __BSP_IO_H_ */
