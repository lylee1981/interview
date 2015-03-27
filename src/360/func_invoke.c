#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void func1(char a[]);
void func2(char *a);

void func1_int(int a[]);
void func2_int(int *a);

void func2_int(int *a) {

	printf("sizeof a: %d\n", sizeof(a));
}

void 
func1_int(int a[]) {
	
	printf("sizeof a: %d\n", sizeof(a));
}

void func2(char *a) {

	printf("sizeof a: %d\n", sizeof(a));
}

void 
func1(char a[]) {
	
	printf("sizeof a: %d\n", sizeof(a));
}


int main(void) {

	char *b = "abcde";
	char a[] = "abcde";
	printf("sizeof char array: %d\n", sizeof(a));
	func1(a);
	func2(a);
	
	printf("sizeof char pointer: %d\n", sizeof(b));
	func1(b);
	func2(b);

	int x[] = {1,2,3,4,5};
	printf("sizeof char pointer: %d\n", sizeof(x));
	func1_int(x);
	func2_int(x);
	return 0;

}
