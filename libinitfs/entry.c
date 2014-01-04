#include <initfs.h>
#include <libinitfs.h>

int initfs_entryVerifyMagic(initfs_entry_t entry)
{
	return entry.magic - 0xF5; //Should be 0 if correct
}

initfs_entrytypes_t initfs_getEntryType(initfs_entry_t entry)
{
	switch(entry.type)
	{
		case 0x0:
			return ENTRY_FILE;
		case 0x1:
			return ENTRY_EXECTUABLE;
		default:
			return ENTRY_NOT_A_ENTRY;
	}
}

const char* initfs_getEntryLabel(initfs_entry_t entry)
{
	const char *name = entry.name;
	return name;
}

int initfs_entryHasData(initfs_entry_t entry) //Returns 0 for no, returns # of bytes if it does
{
	if(entry.data_addr)
	{
		if(entry.data_length)
		{
			return entry.data_length;
		}
	}
	return 0;
}

initfs_data_pointer_t initfs_getEntryDataPointer(initfs_entry_t entry)
{
	initfs_data_pointer_t builder;
	if(initfs_entryHasData(entry)==0)
	{
		return builder;
	}
	builder.length=entry.data_length;
	builder.address=entry.data_addr;
	return builder;
}