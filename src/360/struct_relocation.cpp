#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

struct var {
	char c[6];
	void *p;
	int i;
	double d;
	short s;
};

struct var2 {
	double d;
	void *p; 
	char c[6];
	short s;
	int i;
};

int main(void) {

	struct var v;
	struct var2 v2;

	size_t size = sizeof(struct var);
	cout << "sizeof struct var is: " << size << endl;
	cout << "sizeof struct var2 is: " << sizeof(v2) << endl;


	cout << "sizeof var.s is: " << sizeof(v.s) << endl;
	cout << "sizeof var.p is: " << sizeof(v.p) << endl;
	cout << "sizeof var.i is: " << sizeof(v.i) << endl;
	cout << "sizeof var.c is: " << sizeof(v.c) << endl;
	cout << "sizeof var.d is: " << sizeof(v.d) << endl;

	return 0;

}
