#include <stdio.h>

#include "system_BlueNRG_LP.h"
#include "ble_const.h"
#include "bluenrg_lp_stack.h"

#include "bluenrg_lp_it.h"
#include "bsp_io.h"
#include "BLE_config.h"

NO_INIT(uint32_t dyn_alloc_a[DYNAMIC_MEMORY_SIZE>>2]);

void ModulesInit(void)
{
	uint8_t ret;
	BLE_STACK_InitTypeDef BLE_STACK_InitParms = BLE_STACK_INIT_PARAMETERS;
	
	LL_AHB_EnableClock(LL_AHB_PERIPH_PKA | LL_AHB_PERIPH_RNG);
	
	
	
}

int main(void)
{
	if (SystemInit(SYSCLK_64M, BLE_SYSCLK_32M) != SUCCESS) {
		/* Error during system clock configuration take appropriate action */
    while(1);
	}
	/* Configure IOs for power save modes */
	BSP_IO_Init();
	/* Init the UART peripheral */
	BSP_COM_Init();
	/* Init BLE stack, HAL virtual timer and NVM modules */
  ModulesInit(); 
	
	while(1);
	
}
