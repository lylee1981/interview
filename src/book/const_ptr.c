#include <stdlib.h>
#include <stdio.h>

int main(void) {

	int x = 10;

	const int *q = &x;

	printf("x: %d\n", x);
	printf("q value: %d\n", *q);
	printf("q addr: %p\n", q);

	int y = 100;
	q = &y;

	printf("q value: %d\n", *q);
	printf("q addr: %p\n", q);
	return 0;

	/*
	int x = 10;
	int * const q = &x;
	printf("x: %d\n", x);
	printf("q value: %d\n", *q);
	printf("q addr: %p\n", q);

	int y = 100;
	*q = y;
	
	printf("q value: %d\n", *q);
	return 0;
	*/

	/*
	const int myint;
	printf("%d\n", myint);

	const int i = 10;
	int *p = &i;

	int j = 20;
	const int *ptr = &j;

	int * const p2 = &j;
	printf("*p2: %d\n", *p2);
	*p2 = i;

	printf("*p2: %d\n", *p2);
	

	printf("*p: %d\n", *p);
	printf("*ptr: %d\n", *ptr);
	return 0;
	*/

}
