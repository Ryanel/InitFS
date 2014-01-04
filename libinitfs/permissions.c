#include <initfs.h>
#include <libinitfs.h>
#include <stdio.h>
initfs_permissions_t initfs_getPermissions(initfs_directory_entry_t entry)
{
	switch(entry.attributes)
	{
		case 0x0:
			return NO_ACCESS;
		case 0x1:
			return READ;
		case 0x2:
			return READ_WRITE;
		default:
			printf("(libinitfs) error: Permissions out of bounds! Not allowing access!\n");
			return NO_ACCESS;
	}
}

void initfs_setPermissions(initfs_directory_entry_t *entry, initfs_permissions_t level)
{
	if(entry->attributes != NO_ACCESS)
	{
		entry->attributes=level;
	}
	else
	{
		printf("(libinitfs) error: Can't write permissions, no permissions!\n");
	}
}

void initfs_setPermissions_force(initfs_directory_entry_t *entry, initfs_permissions_t level)
{
	if(entry->attributes == NO_ACCESS)
	{
		printf("(libinitfs) warning: SHOULDN'T write permissions, no permissions!\n");
	}
	entry->attributes=level;
}

int initfs_verifyPermissions(initfs_directory_entry_t entry)
{
	initfs_permissions_t level = initfs_getPermissions(entry);
	if (level != entry.attributes)
	{
		return 1;
	}
	return 0;
}