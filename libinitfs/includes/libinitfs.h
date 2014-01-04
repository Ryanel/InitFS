#ifndef LIB_INITFS_H
#define LIB_INITFS_H
#include "initfs.h"

//Permissions
initfs_permissions_t initfs_getPermissions(initfs_directory_entry_t entry);
void initfs_setPermissions(initfs_directory_entry_t *entry, initfs_permissions_t level);
//setPermissions force isn't here as it is depreciated
int initfs_verifyPermissions(initfs_directory_entry_t entry);

//Directories
const char* initfs_getDirectoryLabel(initfs_directory_entry_t entry);
unsigned int initfs_detectDirectoryAmount(initfs_directory_map_t toDetect);
signed int initfs_verifyDirectoryAmount(initfs_directory_map_t toDetect);

//Superblock
int initfs_verifySuperblockIntegrety(initfs_superblock_t superblock);
const char * initfs_getBuilderIdentity(initfs_superblock_t superblock);
int initfs_verifyDevKey(initfs_superblock_t superblock);

//Entry
int initfs_entryVerifyMagic(initfs_entry_t entry);
const char* initfs_getEntryLabel(initfs_entry_t entry);
int initfs_entryHasData(initfs_entry_t entry);
initfs_data_pointer_t initfs_getEntryDataPointer(initfs_entry_t entry);

#endif
