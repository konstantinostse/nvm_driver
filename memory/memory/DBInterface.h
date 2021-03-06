/**
 * @file DBInterface.h
 *
 * @brief Database interface function prototypes.
 * 
 * Functions prototypes for interacting with the Attributes Database. 
 */

#ifndef __NVM_DB_INTERFACE__
#define __NVM_DB_INTERFACE__

#include "attributeDatabase.h"

/** @brief Load to the heap (attUIntX_inst)
*          all the attribute from the attArray[].
*          This function allocate resources 
*          in the Heap memory for the Database.
*  @return 0 for Success and -1 for failure.
*/
int loadDatabaseInHeap();

/** @brief Unload from the heap all the attributes 
*          which they were loaded from the attArray[] with the
*          function loadDatabase().
*          This function deallocate resources
*          in the Heap memory which they were allocated for the Database.
*  @return 0 for Success and -1 for failure.
*/
int unloadDatabaseFromHeap();

/** @brief Write Database from Heap memory (attUIntX_t)
*          to the NVM.
*  @return 0 for Success and -1 for failure.
*/
int writeDatabaseToNvm();

/** @brief Read an attribute from the NVM.
*          In order to use this function the database 
*          should be loaded both in NVM ( writeDatabaseToNvm() )
*          and Ram ( loadDatabaseInHeap() ).
*  @param attrId Attribute ID in the database.
*  @param pLenght Size of the Attributes Data field. 
*                 Size is in bytes and it will be returned from the function.
*  @param pValue Pointer to Array with the attrinute's data. 
*                 It supports UInt8_t , UInt16_t and UInt32_t types.
*  @return 0 for Success and -1 for failure.
*/
gpNvm_Result gpNvm_getAttribute(gpNvm_AttrId attrId, UInt8_t* pLenght, void* pValue);

/** @brief Writes an attribute in the NVM Database.
*         In order to use this function the database
*          should be loaded both in NVM ( writeDatabaseToNvm() )
*          and Ram ( loadDatabaseInHeap() ).
*  @param attrId Attribute ID in the database.
*  @param pLenght Size of the data for reading.It should not be bigger
*                 from the maximum data lenght of the attribute.
*                 Size should be in bytes.
*  @param pValue Pointer to Array with the attrinute's data to 
*				 be written in the nvm Database.It supports UInt8_t , 
*				 UInt16_t and UInt32_t types.
*  @return 0 for Success and -1 for failure.
*/
gpNvm_Result gpNvm_setAttribute(gpNvm_AttrId attrId, UInt8_t pLenght, void* pValue);

/** @brief Reads an attribute from the NVM Database.
*          In order to use this function ,it is not needed the database
*          to be loaded in the NVM ( writeDatabaseToNvm() )
*          or Ram ( loadDatabaseInHeap() ) or both.
*  @param attribute Pointer to attUIntX_t type. It contains the attrinute's data to
*				    be written in the nvm Database. attUIntX_t pointer is used also
*                   for loading the database in Ram.
*  @param attributeNum Attribute ID.
*  @return 0 for Success and -1 for failure.
*/
int readDatabaseAttribute(attUIntX_t* const attribute, UInt8_t attributeNum);

/** @brief Writes an attribute in the NVM Database.
*          In order to use this function ,it is not needed the database
*          to be loaded in the NVM ( writeDatabaseToNvm() )
*          or Ram ( loadDatabaseInHeap() ) or both.
*  @param attribute Pointer to attUIntX_t type. It contains the attrinute's data which
*				    they was read from the nvm Database. attUIntX_t pointer is used also 
*                   for loading the database in Ram. 
*  @param attributeNum Attribute ID.
*  @return 0 for Success and -1 for failure.
*/
int writeDatabaseAttribute(attUIntX_t* const attribute, UInt8_t attributeNum);

#endif /* __NVM_DB_INTERFACE__ */

