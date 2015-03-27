#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;


class Base {
public:
	virtual void func(){
		cout << "func" << endl;
		char *q;
	};
	virtual void func2(){
	
		cout << "func2" << endl;
		char *p;
	};
	Base() {
		cout << "Base Constructor" << endl;
	}
	virtual ~Base() {
	
		cout << "Base Destructor" << endl;
	}
	int x;
};


int main(void) {

	printf("sizeof Base: %d\n", sizeof(Base));
	Base *b = new Base;
	b->func();
	b->func2();
	printf("sizeof Base 's func: %d\n", sizeof(Base::func));
	printf("sizeof Base 's x: %d\n", sizeof(b->x));

	delete b;
	return 0;

}
