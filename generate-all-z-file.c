#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd;
	char *fname;
	unsigned long long fsize;
	char *buf;

	if (argc < 2) {
		printf("Usage: generate-all-z-file filename <size>\n");
		return -1;
	}

	fname = argv[1];
	fd = open(fname, O_WRONLY);

	if (argc == 3) {
		fsize = strtoull(argv[2], NULL, 10);
	} else {
		fsize = 1024 * 1024 * 1024;
	}

	buf = malloc(fsize);
	memset(buf, 'z', fsize);

	write(fd, buf, fsize);

	close(fd);

	return 0;
}