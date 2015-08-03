/* ****************************************************************
*
* Copyright 2014 Samsung Electronics All Rights Reserved.
*
*
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
******************************************************************/

/**
 * @file
 *
 * This file contains the util function for LE adapter. This maintains the
 * list of services an individual GATT Client connected to and operations on
 * that list, such as getting the service info with BD address or with
 * position etc. This is mainly useful for the multicast transmission of
 * data where client needs to have the info of all the services to which it
 * is connected.
 */

#ifndef TZ_BLE_UTIL_H_
#define TZ_BLE_UTIL_H_

#include <bluetooth.h>

#include "cacommon.h"

/**
 * @struct BLEServiceInfo
 * @brief Information regarding the GATTServer
 *
 * This structure holds the infomation about the GATTServer
 * in the service and the characteristic level
 */
typedef struct
{
    bt_gatt_attribute_h service_clone; /**< GATT attribute handler for the OIC service. */
    bt_gatt_attribute_h read_char;     /**< GATT attribute handler for OIC read characteristic.
                                            Server will read.*/
    bt_gatt_attribute_h write_char;    /**< GATT attribute handler for OIC write characteristic.
                                            server will write*/
    char *bdAddress;                   /**< BD address where OIC service is running. */
} BLEServiceInfo;

/**
 * @struct BLEServiceList
 * @brief List of the BLEServiceInfo structures.
 *
 * A list of BLEServiceInfo and gives the info about all the
 * the registered services from the client side.
 */
typedef struct _BLEServiceList
{
    BLEServiceInfo *serviceInfo;    /**< BLEServiceInfo structure from an OIC Server */
    struct _BLEServiceList *next;   /**< Next reference to the List*/
} BLEServiceList;

/**
 * @enum CHAR_TYPE
 * @brief Different characteristics types.
 *
 *  This provides information of different characteristics
 *  which will be added to OIC service.
 */
typedef enum
{
    BLE_GATT_WRITE_CHAR = 0, /**< write_char This will be used to get the unicast response */
    BLE_GATT_READ_CHAR,      /**< read_char This will be used update value to OIC server */
    BLE_GATT_NOTIFY_CHAR     /**< Reserved char for the time being. */
} CHAR_TYPE;

/**
 * @struct stGattCharDescriptor_t
 * @brief Stores the information required to set the descriptor value of the Service.
 */
typedef struct gattCharDescriptor
{
    bt_gatt_attribute_h characteristic; /**< The attribute handle of descriptor */
    uint8_t *desc;                      /**< Descriptor handle of characteristic, in byte array*/
    int total;                          /**< The total number of descriptor in a characteristic */
} stGattCharDescriptor_t;

/**
 * @brief  Used to increment the registered service count.
 * @return NONE
 */
void CAIncrementRegisteredServiceCount();

/**
 * @brief  Used to decrement the registered service count.
 *
 * @return NONE.
 */
void CADecrementRegisteredServiceCount();

/**
 * @brief  Used to reset the registered service count.
 * @return  NONE
 */
void CAResetRegisteredServiceCount();

/**
 * @brief  Used to get the total registered service count.
 * @return  Total registered service count.
 */
int32_t  CAGetRegisteredServiceCount();

/**
 * @brief  Used to create BLEServiceInfo structure with server handler and BD address will be
 *         created.
 * @param bdAddress      [IN] BD address of the device where GATTServer is running.
 * @param service        [IN] service attribute handler.
 * @param bleServiceInfo [IN] Pointer where serviceInfo structure needs to be stored.
 *                            Memory will be allocated here and needs to be cleared by caller.
 * @return #CA_STATUS_OK or Appropriate error code
 * @retval #CA_STATUS_OK  Successful
 * @retval #CA_STATUS_INVALID_PARAM  Invalid input argumets
 * @retval #CA_STATUS_FAILED Operation failed
 */
CAResult_t CACreateBLEServiceInfo(const char *bdAddress, bt_gatt_attribute_h service,
                                  BLEServiceInfo **bleServiceInfo);

/**
 * @brief  Used to append the characteristic info to the already created serviceInfo structure.
 *
 * @param characteristic [IN] Charecteristic attribute handler.
 * @param type           [IN] Specifies whether its BLE_GATT_READ_CHAR or BLE_GATT_WRITE_CHAR
 * @param bleServiceInfo [IN] Pointer where serviceInfo structure needs to be appended with
 *                            char info.
 * @return #CA_STATUS_OK or Appropriate error code
 * @retval #CA_STATUS_OK  Successful
 * @retval #CA_STATUS_INVALID_PARAM  Invalid input argumets
 * @retval #CA_STATUS_FAILED Operation failed
 */
CAResult_t CAAppendBLECharInfo(bt_gatt_attribute_h characteristic, CHAR_TYPE type,
                               BLEServiceInfo *bleServiceInfo);

/**
 * @brief  Used to add the ServiceInfo structure to the Service List.
 *
 * @param serviceList    [IN] Pointer to the ble service list which holds the info of list of
 *                            service registered from client.
 * @param bleServiceInfo [IN] Pointer where serviceInfo structure needs to be appended with
 *                            char info.
 * @return #CA_STATUS_OK or Appropriate error code
 * @retval #CA_STATUS_OK  Successful
 * @retval #CA_STATUS_INVALID_PARAM  Invalid input argumets
 * @retval #CA_STATUS_FAILED Operation failed
 */
CAResult_t CAAddBLEServiceInfoToList(BLEServiceList **serviceList,
                BLEServiceInfo *bleServiceInfo);

/**
 * @brief  Used to remove the ServiceInfo structure from the Service List.
 *
 * @param serviceList    [IN] Pointer to the ble service list which holds the info of list of
 *                            service registered from client.
 * @param bleServiceInfo [IN] Pointer where serviceInfo structure needs to be appended with
 *                            char info.
 * @param bdAddress      [IN] BD address of the device where GATTServer is disconnected.
 *
 * @return #CA_STATUS_OK or Appropriate error code
 * @retval #CA_STATUS_OK  Successful
 * @retval #CA_STATUS_INVALID_PARAM  Invalid input argumets
 * @retval #CA_STATUS_FAILED Operation failed
 */
CAResult_t CARemoveBLEServiceInfoToList(BLEServiceList **serviceList,
                                        BLEServiceInfo *bleServiceInfo,
                                        const char *bdAddress);

/**
 * @brief  Used to get the serviceInfo from the list.
 *
 * @param serviceList    [IN]  Pointer to the ble service list which holds the info of list
 *                             of service registered from client.
 * @param bdAddress      [IN]  BD address of the device where GATTServer information is required.
 * @param bleServiceInfo [OUT] Pointer where serviceInfo structure needs to provide the service
 *                             and char info.
 * @return #CA_STATUS_OK or Appropriate error code
 * @retval #CA_STATUS_OK  Successful
 * @retval #CA_STATUS_INVALID_PARAM  Invalid input argumets
 * @retval #CA_STATUS_FAILED Operation failed
 */
CAResult_t CAGetBLEServiceInfo(BLEServiceList *serviceList, const char *bdAddress,
                               BLEServiceInfo **bleServiceInfo);

/**
 * @brief  Used to get the serviceInfo from the list by position.
 *
 * @param serviceList    [IN]  Pointer to the ble service list which holds the info of list
 *                             of service registered from client.
 * @param position       [IN]  The service information of particular position in the list.
 * @param bleServiceInfo [OUT] Pointer where serviceInfo structure needs to provide the service
 *                             and char info.
 * @return #CA_STATUS_OK or Appropriate error code
 * @retval #CA_STATUS_OK  Successful
 * @retval #CA_STATUS_INVALID_PARAM  Invalid input argumets
 * @retval #CA_STATUS_FAILED Operation failed
 */
CAResult_t CAGetBLEServiceInfoByPosition(BLEServiceList *serviceList, int32_t position,
                                         BLEServiceInfo **bleServiceInfo);

/**
 * @brief  Used to clear BLE service list
 *
 * @param  serviceList [IN] Pointer to the ble service list which holds the info of list of
 *                          service registered from client.
 * @return NONE
 */
void CAFreeBLEServiceList(BLEServiceList *serviceList);

/**
 * @brief Used to get remove particular BLE service info from list
 * @param serviceinfo [IN] Pointer to the structure which needs to be cleared.
 *
 * @return NONE
 */
void CAFreeBLEServiceInfo(BLEServiceInfo *bleServiceInfo);

/**
 * @brief  Used to check whether found handle is OIC service handle or not.
 *
 * @param serviceHandle [IN] Discovered service handle(unique identifier for service)
 * @return #CA_STATUS_OK or Appropriate error code
 * @retval #CA_STATUS_OK  Successful
 * @retval #CA_STATUS_INVALID_PARAM  Invalid input argumets
 * @retval #CA_STATUS_FAILED Operation failed
 */
CAResult_t CAVerifyOICServiceByServiceHandle(bt_gatt_attribute_h serviceHandle);

/**
 * @brief  Used to check whether UUID of the discovered device is OIC service or not.
 *
 * @param  serviceUUID [IN] Service UUID
 * @return #CA_STATUS_OK or Appropriate error code
 * @retval #CA_STATUS_OK  Successful
 * @retval #CA_STATUS_INVALID_PARAM  Invalid input argumets
 * @retval #CA_STATUS_FAILED Operation failed
 */
CAResult_t CAVerifyOICServiceByUUID(const char* serviceUUID);

/**
 * @brief  Used to get the Error message.
 * @param err [IN] Error code(#bt_error_e)
 * @return  Error string corresponding to the BT error code.
 */
const char *CABTGetErrorMsg(bt_error_e err);

#endif /* TZ_BLE_UTIL_H_ */
