#ifndef __BLE_CONFIG_H_
#define __BLE_CONFIG_H_

/* 默认配置一个蓝牙收发的服务 */
#define NUM_APP_GATT_SERVICES_CONF 			1 
#define NUM_APP_GATT_ATTRIBUTES_CONF    5


#define NUM_OTA_GATT_ATTRIBUTES_CONF		0

/* Number of GATT attributes needed for the demo. */
#define NUM_GATT_ATTRIBUTES     (NUM_APP_GATT_SERVICES_CONF + NUM_APP_GATT_ATTRIBUTES_CONF + NUM_OTA_GATT_ATTRIBUTE_CONF)

#define DYNAMIC_MEMORY_SIZE 10

/* This structure contains memory and low level hardware configuration data for the device */
#define BLE_STACK_INIT_PARAMETERS {    \
	.BLEStartRamAddress = (uint8_t*)dyn_alloc_a,    \
	.TotalBufferSize = DYNAMIC_MEMORY_SIZE,			\
	.NumAttrRecords = NUM_GATT_ATTRIBUTES,			\
	\
}

#endif /* __BLE_CONFIG_H_ */
