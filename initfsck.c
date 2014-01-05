#include <stdio.h>
#include "libinitfs/includes/libinitfs.h"
#include "libinitfs/includes/initfs.h"
const char* path="test/Sample Filesystem.bin";
FILE *filesystem;
int main()
{
	printf("initfsck - Initial Ramdisk Filesystem Check\n");
	printf("(!): This version of initfsck does NOT support write operations\n");
	printf("Opening filesystem...\n");
	filesystem = fopen(path, "r");
	if (filesystem == NULL) {
		printf("(!): Cannot open file %s for verification!\n",path);
		return 1;
	}
	initfs_superblock_t superblock;
	fread(&superblock, sizeof(superblock), 1, filesystem);
	int superblock_integrety = initfs_verifySuperblockIntegrety(superblock);
	if(superblock_integrety)
	{
		switch(superblock_integrety)
		{
			case 0x0:
				printf("(!) Internal error at line %d. Exiting...\n",__LINE__);
				return 848;
			case 0x1:
				printf("(!) Superblock magic damaged. Suppost to be 0xF5(%X).\n(Are you sure this is a initfs filesystem?\n",superblock.magic);
				return 1;
		}
	}
	printf("Superblock magic:\t 0x%X\n",superblock.magic);
	printf("Filesystem Version:\t 0x%X\n",superblock.fs_version);
	printf("Filesystem Flags:\t 0x%X\n",superblock.flags);
	printf("Created by:\t\t %s\n",initfs_getBuilderIdentity(superblock));
	printf("Dev key:\t\t %d (%x)\n",initfs_verifyDevKey(superblock),superblock.dev_key);
	printf("Address of directory map:0x%X\n",superblock.directory_map);
	if(superblock.directory_map>=0xF000000)
	{
		printf("(?):The directory map is at 0xF000000 or above! Check the edianness.\n");
	}
	printf("Verifying Directory Map...\n");
}