#include "testCrcCheck.h"

#include "crcCheck.h"

#include <assert.h>

static UInt8_t testArray1[5] = { 1,2,3,4,5 };
static const UInt8_t crc8Value = 1;
static UInt32_t testArray2[5] = { 8,2,6,9,10 };
static const UInt32_t crc32Value = 15;

static void setup()
{
    // This gets run before every test.
}

static void teardown()
{
    // This gets run after every test.
}


void testCrcCheck()
{
    UInt8_t crc8ValueTemp  = 0;
    UInt8_t crc32ValueTemp = 0;


    crc8ValueTemp = crcCheck(testArray1, 5);
    assert((crc8ValueTemp == crc8Value) && ( " Wrong CRC !!!"));

    crc32ValueTemp = crcCheck(testArray2, 5);
    assert((crc32ValueTemp == crc32Value) && (" Wrong CRC !!!") );
}