#ifndef INITFS_STRUCT
#define INITFS_STRUCT
#define byte unsigned char
typedef struct
{
	byte magic;
	byte fs_version;
	byte flags;
	byte builder_identity;
	byte dev_key;
	byte reserved[7];
	unsigned int directory_map;
} initfs_superblock_t;
typedef struct 
{
	unsigned int no_directories;
	unsigned int directory_entries[127];
} initfs_directory_map_t;

typedef struct
{
	byte name[46];
	byte id;
	byte attributes; // 0 - NO ACCESS, 1 - READ
} initfs_directory_entry_t;

typedef struct
{
	byte magic; //0xF5
	byte type; // 0 - file, 1 - executable
	byte name[48];
	unsigned int data_addr;
	unsigned int data_lenght;
	unsigned short filler; //To make it 64 bytes.
} initfs_entry_t;

typedef enum { NO_ACCESS, READ, READ_WRITE } initfs_permissions_t;
#endif
