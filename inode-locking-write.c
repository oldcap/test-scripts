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
		printf("Usage: inode-locking-write <file name> <offset>\n");
		return -1;
	}

	char * buf = memalign(4096, BUF_SIZE);
	memset(buf, 'h', BUF_SIZE)

	int fd = open(argv[1], O_RDWR | O_DIRECT);
	unsigned long long offset;
	if (argc > 2) {
		offset = strtoull(argv[2], NULL, 10);
	} else {
		offset = 0;
	}

	
	if (lseek(fd, offset, SEEK_SET) != offset) {
		perror("Cannot seek");
	}
	write(fd, buf, BUF_SIZE);

	free(buf);
	close(fd);
	return 0;
}