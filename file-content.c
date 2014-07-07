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
		printf("Usage: file-content <file name> <offset>\n");
		return -1;
	}

	char * buf = malloc(BUF_SIZE);

	int fd = open(argv[1], O_RDONLY);

	while(1) {
		read(fd, buf, BUF_SIZE);
		printf("%s\n", buf);
	}

	free(buf);
	close(fd);
	return 0;
}