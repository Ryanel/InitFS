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
	unsigned int root_mapblock;
};
struct initfs_mapblock {
	unsigned char magic;
	unsigned char type;
	unsigned char name[32];
	unsigned int data_addr; //O if no data
	unsigned int data_lenght; //O if no data
	unsigned int next_block;
	unsigned short filler; //To make it 48 bytes.

};
#endif
