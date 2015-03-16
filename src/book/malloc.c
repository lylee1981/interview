#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

void malloc_memory(char *ptr, size_t num);
void change_value(char *ptr);
char *malloc_memory2(char *ptr, size_t num);
void malloc_memory3(char **ptr, size_t num);

void 
change_value(char *ptr) {
	
	printf("before change value, addr in internal: %p\n", ptr);
	printf("before change value, value in internal: %s\n", ptr);
	//strcpy(ptr, "aaaaa");
	ptr[0]='x';
	//*ptr[0]='x';
	//strcpy(ptr, "hi");
}

void 
malloc_memory3(char **ptr, size_t num) {

	printf("before malloc, addr in internal: %p\n", *ptr);
	*ptr = (char *)malloc(sizeof(char) * num);
	printf("after malloc, addr in internal: %p\n", *ptr);
}

char *
malloc_memory2(char *ptr, size_t num) {
	
	ptr = (char *)malloc(sizeof(char) * num);
	printf("addr in internal: %p\n", ptr);
	return ptr;
}

void 
malloc_memory(char *ptr, size_t num) {

	printf("before malloc, addr in internal: %p\n", ptr);

	ptr = (char *)malloc(sizeof(char) * num);

	printf("addr in internal: %p\n", ptr);
}

int main(void) {

	//char *source = "123456";
	char *source = (char *)malloc(6);
	strcpy(source, "12345");
	printf("source 's addr: %p\n", source);
	printf("source 's value: %s\n", source);

	char *ptr = source;
	printf("ptr 's addr: %p\n", ptr);
	printf("ptr 's value: %s\n", ptr);

	size_t num = 10;
	//malloc_memory3(&ptr, num);
	change_value(source);
	printf("ptr 's value: %s\n", source);


	return 0;
	printf("source 's addr: %p\n", source);
	printf("ptr 's addr: %p\n", ptr);
	//ptr = malloc_memory2(ptr, num);
	printf("addr: %p\n", ptr);
	strcpy(ptr, "hello");

	free(ptr);

	return 0;

}
