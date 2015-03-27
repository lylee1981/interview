#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static int fd;

static void release();
static void openfd(void);
static void read_and_print(int fd, int count);

static void 
read_and_print(int fd, int count) {

	char buffer[3];
	size_t n;
	pid_t pid;
	pid = getpid();

again_read:
	while( count > 0 ) {
		memset(buffer, '\0', 2);
		n = read(fd, buffer, 2);
		buffer[2] = '\0';
		printf("process: %d, read fd: %d %d bytes, content: %s\n", \
				(unsigned int)pid, \
				fd, \
				n, \
				buffer);
		count--;
		sleep(1);
		goto again_read;
	}
}

static void 
openfd(void) {

	const char *path = "/root/workspace/mygits/interview/src/360/file_test";


	fd = open(path, O_RDONLY);
	
	if(fd == -1) {
		perror("open");
		goto release;
	}

	return;

release:
	release();
	return;
}

static void release() {
	if(fd != 0) {
		printf("fd %d closed\n", fd);
		close(fd);
	}
}


int main(void) {
	fd = -1;

	int err;

	pid_t pid;

	openfd();

	pid = fork();
	if(pid < 0) {
		release();
		exit(0);	
	}

	if (pid > 0) {
		printf("in master process, sub-pid: %d, fd: %d\n", (unsigned int)pid, fd);
		read_and_print(fd, 2);
	} else if (pid == 0) {

		pid = getpid();
		printf("in sub process[%d], fd: %d\n", (unsigned int)pid, fd);
		read_and_print(fd, 2);
	}

	release();

	return 0;
}
