#define _GNU_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <malloc.h>
#include <unistd.h>
#include <errno.h>
#define BUF_SIZE 20480


int main(int argc, char **argv) {
	if (argc < 3) {
		printf("Usage: file-content <file name> <offset>\n");
		return -1;
	}

	int ret;
	char * buf = malloc(BUF_SIZE);

	int fd = open(argv[1], O_RDONLY);
	unsigned long long offset = strtoull(argv[2], NULL, 10);

	printf("Seeking to %llu\n", offset);

	ret = lseek(fd, offset, SEEK_SET);
	if (ret != offset) {
		perror("Cannot seek-%d", ret);
	}
	ret = read(fd, buf, BUF_SIZE);
	if (ret != BUF_SIZE) {
		perror("Cannot read, ");
	}
	printf("%s\n", buf);

	free(buf);
	close(fd);
	return 0;
}