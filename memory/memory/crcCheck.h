/**
 * @file crcCheck.h
 *
 * @brief CRC calculation functions prototypes
 */

#if !defined(__CRC_CHECK_H__) && !defined(__cplusplus)
#define __CRC_CHECK_H__

#include <stdint.h>
#include "attributes.h"

/** @brief Calculate the crc for a UInt8_t ,UInt16_t or 
 *         UInt32_t array(data) with size sz and return the crc value.
 *  @param[in]    data      Void pointer to array with the Data.
 *  @param[in]    crc       Void Pointer to crc value .
 *  @param[in]    sz        Size of the array.
 *  @param[in]    dataType  Data type of the array and crc.
 *                          uint8PtrType for pointer to UInt8_t.
 *                          uint16PtrType for pointer to UInt16_t.
 *                          uint32PtrType for pointer to UInt32_t.
 *  @return                 crc calculation Status. 0 for success and -1 for failure.
 */
int crcCheck(void* data, void* crc, size_t sz, UInt8_t dataType);

#endif /* __CRC_CHECK_H__ */