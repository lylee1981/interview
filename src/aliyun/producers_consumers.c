#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>



static pthread_t pthid, cthid;
static pthread_cond_t cond;
static pthread_mutex_t mux;
static int release;

static void *thread_for_consume(void *args);
static void *thread_for_produce(void *args);
static void init(void);

static void 
init(void) {
	release = 0;
	pthread_mutex_init(&mux, NULL);
	pthread_cond_init(&cond, NULL);
}

static void *
thread_for_produce(void *args) {

	int release_old;
	pthid = pthread_self();

	pthread_mutex_lock(&mux);
	release_old = release;
	release = 1;
	printf("[produce_thread_%u] release changed, old: %d, new: %d\n", \
			(unsigned int)pthid, \
			release_old, \
			release);
	pthread_cond_signal(&cond);
	pthread_mutex_unlock(&mux);
}

static void *
thread_for_consume(void *args) {
	
	cthid = pthread_self();
	pthread_mutex_lock(&mux);
	while( release == 0 ) {
		printf("[consume_thread_%u] wait...\n", (unsigned int)cthid);
		pthread_cond_wait(&cond, &mux);
	}
	pthread_mutex_unlock(&mux);

	printf("[consume_thread_%u] current release: %d\n", (unsigned int)cthid, release);
	printf("[consume_thread_%u] todo consume data\n", (unsigned int)cthid);
}

int main(void) {

	init();

	pthread_create(&cthid, NULL, (void *)thread_for_consume, NULL);

	sleep(1);

	pthread_create(&pthid, NULL, (void *)thread_for_produce, NULL);
	

	pthread_join(cthid, NULL);
	pthread_join(pthid, NULL);

	return 0;

}
