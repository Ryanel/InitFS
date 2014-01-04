typedef struct
{
	byte magic; //0xF5
	byte type; // 0 - file, 1 - executable
	byte name[48];
	unsigned int data_addr;
	unsigned int data_lenght;
	unsigned short filler; //To make it 64 bytes.
} initfs_entry_t;

void initfs_entryVerifyMagic()
{

}