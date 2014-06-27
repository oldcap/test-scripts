#define _GNU_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <malloc.h>
#include <unistd.h>
#define BUF_SIZE 20480

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("Usage: inode-locking <file name>\n");
		return -1;
	}

	char * buf = memalign(4096, BUF_SIZE);

	int fd = open(argv[1], O_RDWR | O_DIRECT);

	while(1) {
		sleep(1);
		read(fd, buf, 4096);
		printf("%s\n", buf);
	}

	return 0;
}