#include <stdio.h>

#include "system_BlueNRG_LP.h"


#include "bluenrg_lp_it.h"
#include "bsp_io.h"


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
	
	printf("Done!\r\n");
	
	while(1);
	
}
