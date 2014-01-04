#include <initfs.h>
#include <libinitfs.h>

int initfs_verifySuperblockIntegrety(initfs_superblock_t superblock)
{
	if(superblock.magic != 0xF5)
	{
		return 1;
	}
	if(superblock.fs_version != 0x1)
	{
		return 2;
	}
	if(superblock.builder_identity)
	{
		if( initfs_getBuilderIdentity(superblock) == 0)
		{
			return 3;
		}
	}
	if(superblock.dev_key)
	{
		if( initfs_verifyDevKey(superblock) != 0)
		{
			return 4;
		}
	}
	if(superblock.directory_map == 0)
	{
		return 5;
	}
	return 0;
}

const char * initfs_getBuilderIdentity(initfs_superblock_t superblock)
{
	switch(superblock.builder_identity)
	{
		case 0x1: //Only valid dev key. Add more to this list as more become avalable
			return "initfscreate";
		default:
			return 0;
	}
}

int initfs_verifyDevKey(initfs_superblock_t superblock)
{
	switch(superblock.dev_key)
	{
		case 0x12: //Only valid dev key. Add more to this list as more become avalable
			return 0;
		default:
			return 1;
	}
}