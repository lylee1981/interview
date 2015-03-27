#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;


class Base {
public:
	virtual void func()=0;
	virtual void func2() {};
	Base() {
		cout << "Base Constructor" << endl;
	}
	virtual ~Base() {
	
		cout << "Base Destructor" << endl;
	}
};

class SubA : public Base {
public:
	SubA() {
		
		cout << "SubA Constructor" << endl;
	}
	virtual ~SubA() {
		
		cout << "SubA Destructor" << endl;
	}

	
	virtual void func() {
		
		cout << "SubA func invoke" << endl;
	}
};


int main(void) {

	printf("sizeof SubA: %d\n", sizeof(SubA));
	printf("sizeof Base: %d\n", sizeof(Base));

	Base *p = new SubA;
	p->func();
	delete p;

	return 0;

}
