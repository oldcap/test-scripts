#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024 * 1024 * 1024

int main(int argc, char **argv)
{
	int fd;
	char *fname;
	unsigned long long fsize;

	char *buf;
	int written = 0;
	int ret = 0;

	if (argc < 2) {
		printf("Usage: generate-all-z-file filename <size>\n");
		return -1;
	}

	fname = argv[1];
	fd = open(fname, O_CREAT | O_WRONLY);

	if (argc == 3) {
		fsize = strtoull(argv[2], NULL, 10);
	} else {
		fsize = 1024 * 1024 * 1024;
	}

	while (written < fsize) {
		buf = malloc(BUF_SIZE);
		memset(buf, 'z', BUF_SIZE);

		ret = write(fd, buf, BUF_SIZE);
		written += ret;
	}

	close(fd);

	return 0;
}