#include <initfs.h>
#include <libinitfs.h>
const char* getDirectoryLabel(initfs_directory_entry_t entry)
{
	return (const char *)entry.name;
}

unsigned int detectDirectoryAmount(initfs_directory_map_t toDetect)
{
	int i=0;
	unsigned int count = 0;
	
	while(i!=(127 - 1))
	{
		if(toDetect.directory_entries[i]!=0x00000000)
		{
			count++;
		}
		else
		{
			break;
		}
		i++;
	}
	return count;
}

signed int verifyDirectoryAmount(initfs_directory_map_t toDetect)
{
	unsigned int directory_map_no=toDetect.no_directories;
	unsigned int detected_no = detectDirectoryAmount(toDetect);
	return directory_map_no - detected_no; //Should return 0 if both are the same, a negative number if detected_no is more, positive if detected_no is less
}

