#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("Usage: inode-locking <file name>\n");
		return -1;
	}

	char buf[20480];

	int fd = open(argv[1], O_RDWR);

	while(1) {
		sleep(1);
		read(fd, buf, 20480);
		printf("%s\n", buf + 20400);
	}

	return 0;
}