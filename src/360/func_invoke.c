#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void func1(char a[]);
void func2(char *a);


void func2(char *a) {

	printf("sizeof a: %d\n", sizeof(a));
}

void 
func1(char a[]) {
	
	printf("sizeof a: %d\n", sizeof(a));
}


int main(void) {

	char a[] = "abcde";
	printf("sizeof int array: %d\n", sizeof(a));
	func1(a);
	func2(a);

	return 0;

}
