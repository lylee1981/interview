#include <stdlib.h>
#include <stdio.h>


static void swap(int a, int b);
static void swap(int *a, int *b);
static void swap3(int *a, int *b);
static void swap4(int &a, int &b);

static 
void swap4(int &a, int &b) {

	int temp = a;	
	a = b;
	b = temp;

	printf("4). in swap, a:	%d, addr:	%p\n", a, &a);	
	printf("4). in swap, b:	%d, addr:	%p\n", b, &b);
}

static 
void swap3(int *a, int *b) {
	
	//swap address of a and b, but value of a and b not changed.

	int *temp = a;
	a = b;
	b = temp;

	printf("3). in swap, a:	%d, addr:	%p\n", *a, a);	
	printf("3). in swap, b:	%d, addr:	%p\n", *b, b);
}

static 
void swap(int a, int b) {

	int temp;
	temp = a;
	a = b;
	b = temp;

	printf("1). in swap, a:	%d, addr:	%p\n", a, &a);
	printf("1). in swap, b:	%d, addr:	%p\n", b, &b);
}

static 
void swap(int *a, int *b) {
	
	int x = 10;
	int *temp = &x;
	//int *temp = *a;
	*a = *b;
	*b = *temp;

	printf("2). in swap, a:	%d, addr:	%p\n", *a, a);	
	printf("2). in swap, b:	%d, addr:	%p\n", *b, b);
}

static void check_reference_and_ptr();

static 
void check_reference_and_ptr() {
	int i=100;
	int j = 200;
	int &p = i;
	printf("p 's addr: %p\n", &p);
	printf("i 's addr: %p\n", &i);
	printf("p addr equal i addr: %d\n", &p == &i);
	printf("p : %d\n", p);

	p = j;

	printf("p 's addr: %p\n", &p);
	printf("i 's addr: %p\n", &i);
	printf("p addr equal i addr: %d\n", &p == &i);
	printf("p : %d\n", p);

	//not allow change reference 's type p 's address
	//&p = j;

}

int main(void) {

	//check_reference_and_ptr();
	
	int a = 5;
	int b = 10;

	printf("1). before swap, a:	%d, addr:	%p\n", a, &a);
	printf("1). before swap, b:	%d, addr:	%p\n", b, &b);
	swap(a, b);

	printf("1). after swap, a:	%d, addr:	%p\n", a, &a);
	printf("1). after swap, b:	%d, addr:	%p\n", b, &b);


	a = 5;
	b = 10;
	printf("2). before swap, a:	%d, addr:	%p\n", a, &a);
	printf("2). before swap, b:	%d, addr:	%p\n", b, &b);
	swap(&a, &b);

	printf("2). after swap, a:	%d, addr:	%p\n", a, &a);
	printf("2). after swap, b:	%d, addr:	%p\n", b, &b);


	a = 5;
	b = 10;

	printf("3). before swap, a:	%d, addr:	%p\n", a, &a);
	printf("3). before swap, b:	%d, addr:	%p\n", b, &b);
	swap3(&a, &b);

	printf("3). after swap, a:	%d, addr:	%p\n", a, &a);
	printf("3). after swap, b:	%d, addr:	%p\n", b, &b);

	a = 5;
	b = 10;

	printf("4). before swap, a:	%d, addr:	%p\n", a, &a);
	printf("4). before swap, b:	%d, addr:	%p\n", b, &b);
	swap4(a, b);

	printf("4). after swap, a:	%d, addr:	%p\n", a, &a);
	printf("4). after swap, b:	%d, addr:	%p\n", b, &b);

	return 0;

}
