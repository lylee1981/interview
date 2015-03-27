#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void *thread_start(void *args);
static void *
thread_start(void *args) {

	const char *path = "/root/workspace/mygits/interview/src/360/file_test";
	int fd;
	char buffer[3];
	size_t n;

	int count;

	fd = -1;
	count = (int)args;

	fd = open(path, O_RDONLY);
	
	if(fd == -1) {
		perror("open");
		goto release;
	}

again_read:
	while( count > 0 ) {
		memset(buffer, '\0', 2);
		n = read(fd, buffer, 2);
		buffer[2] = '\0';
		printf("read fd: %d %d bytes, content: %s\n", fd, n, buffer);
		count--;
		sleep(1);
		goto again_read;
	}

release:
	if(fd != 0) {
		printf("fd %d closed\n", fd);
		close(fd);
	}


	pthread_exit((void *)1);
}

int main(int argc, char *argv[]) {

	pthread_t tid1, tid2;
	int ret;
	void *retval;

	ret = pthread_create(&tid1, NULL, (void *)thread_start, (void *)3);
	ret = pthread_create(&tid2, NULL, (void *)thread_start, (void *)5);

	ret = pthread_join(tid1, &retval);
	ret = pthread_join(tid2, &retval);
	
	return 0;

}
