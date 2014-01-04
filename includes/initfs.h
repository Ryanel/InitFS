#ifndef INITFS_STRUCT
#define INITFS_STRUCT
#define byte unsigned char
struct initfs_superblock{
	byte magic;
	byte fs_version;
	byte flags;
	byte builder_identity;
	byte dev_key;
	byte reserved[7];
	unsigned int directory_map;
};
struct initfs_directory_map
{
	unsigned int no_directories;
	unsigned int directory_entries[127];
};



struct initfs_entry {
	byte magic; //0xF5
	byte type; // 0 - file, 1 - executable
	byte name[48];
	unsigned int data_addr;
	unsigned int data_lenght;
	unsigned short filler; //To make it 64 bytes.
};
#endif
