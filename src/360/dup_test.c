


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void) {

	const char *path = "/root/workspace/mygits/interview/src/360/file_test";
	int fd, nfd;
	char buffer[3];
	size_t n;

	fd = nfd = -1;

	fd = open(path, O_RDONLY);
	
	if(fd == -1) {
		perror("open");
		goto release;
	}

	memset(buffer, '\0', 2);

	n = read(fd, buffer, 2);
	buffer[2] = '\0';
	printf("read fd: %d %d bytes, content: %s\n", fd, n, buffer);

	nfd = dup(fd);
	printf("fd: %d, nfd: %d\n", fd, nfd);

again_read:	
	memset(buffer, '\0', 2);
	n = read(nfd, buffer, 2);
	buffer[2] = '\0';
	printf("read fd: %d %d bytes, content: %s\n", nfd, n, buffer);

	if(fd != -1) {
		close(fd);
		fd = -1;
		goto again_read;
	}

release:
	if(fd != 0) {
		close(fd);
	}

	if(nfd != -1) {
		close(nfd);
	}

	return 0;

}
