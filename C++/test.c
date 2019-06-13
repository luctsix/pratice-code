#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char* buf = NULL;
	char str[] = "helloworld";
	/*
	buf = (char*)malloc(128);
	if(!buf)
	{
		perror("malloc err");
		return -1;
	}
	memset(buf, 0, 128);
	
	int fd = open("test.txt", O_WRONLY|O_CREAT);
	printf("fd:write = %d\n", fd);
	write(fd, str, sizeof(str));
	close(fd);
	
	fd = open("test.txt", O_RDONLY);
	read(fd, buf, 100);
	printf("fd:read = %d\n", fd);
	printf("buf = %s\n", buf);
	close(fd);
	*/
	
	int pid = fork();
	
	return 0;
}
