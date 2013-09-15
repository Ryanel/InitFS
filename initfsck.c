#include <sys/stat.h>
#include <stdio.h>
#include "initfs.h"
FILE *initfs_ptr;

int check(int val,int expectval,char *name)
{
	if(val==expectval)
		printf("[ OK ]:%s is 0x%x\n",name,val);
	else
	{
		printf("[FAIL]:%s is 0x%x (not 0x%x)\n",name,val,expectval);
		return 1;
	}
	return 0;
}

int main()
{
	struct initfs_superblock sb;
	int i;
	printf("initfsck\n");
	printf("[ IO ]:Assuming example.bin for now\n");
	initfs_ptr = fopen("example.bin","rb");
	if(!initfs_ptr)
	{
		printf("No initramfs found!\n");
		return 1;
	}
	fread(&sb,sizeof(sb),1,initfs_ptr);
	if(check(sb.magic,0xF3,"Magic"))
		return 1;
	if(check(sb.fs_version,0x01, "Filesystem Version"))
		return 1;
	printf("Builder Identity:0x%x\n",sb.builder_identity);
	if(sb.dev_key)
	{
		printf("Development Image: yes (unverified)\n");
	}
	fclose(initfs_ptr);
}
