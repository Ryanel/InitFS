#include <initfs.h>
#include <stdio.h>
initfs_permissions_t getPermissions(initfs_directory_entry_t entry)
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
			printf("(libinitfs) error: Permissions out of bounds! Not allowing access");
			return NO_ACCESS;
	}
}