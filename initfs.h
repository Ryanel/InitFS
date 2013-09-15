#ifndef INITFS_STRUCT
#define INITFS_STRUCT
#define byte unsigned char
struct initfs_superblock{
	byte magic;
	byte fs_version;
	byte flags;
	byte builder_identity;
	byte dev_key;
	byte reserved[6];
	unsigned int root_mapblock;
};
struct initfs_mapblock {
	unsigned char magic;
};
#endif
