#include <sys/types.h>
#include <unistd.h>
#include <inttypes.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char **argv) {
	uint8_t buf[4096];
	size_t nread;
	int fd = 0;

	if (argc > 1) {
		for (int i = 1; i < argc; i++){
			fd = open(argv[i], O_RDONLY);
			if (fd < 0) {
				fprintf(stderr, "cannot open %s: %s\n", argv[1], strerror(errno));
				exit(1);
			}
			while ((nread = read(fd, buf, sizeof(buf))) > 0)
				write(1, buf, nread);
		}
	}
	else {
		while ((nread = read(fd, buf, sizeof(buf))) > 0)
			write(1, buf, nread);
	}
	return 0;
}