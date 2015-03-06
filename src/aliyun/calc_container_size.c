
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct ContainerDemo {
	long a;
	int32_t b;
	int32_t c;
	int8_t d;
	char x[7];
	//if char x[0], ..., char x[7], the size of ContainerDemo is 24 bytes
	// if char x[8] and bigger, the sizeof ContainerDemo is bigger than 24 bytes
};

struct ContainerDemo2 {
	long a;
	int32_t b;
	int32_t c;
	int8_t d;
	char *x;
	// x is a pointer, so x use 8 bytes
	// so the size of ContainerDemo2 is 32 bytes
};

int main(void) {

	// machine is X86_64 type

	size_t size = sizeof(struct ContainerDemo);
	printf("size of ContainerDemo type is: %d bytes\n", size);		// 24 bytes
	
	size_t size2 = sizeof(struct ContainerDemo2);
	printf("size of ContainerDemo2 type is: %d bytes\n", size2);		// 32 bytes
	return 0;
}
