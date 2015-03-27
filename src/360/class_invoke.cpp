#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

class TestA {
public:
	void func1() { cout << "TestA::func1" << endl; }
	void func2() { cout << "TestA::func2, " << count << endl; }
	virtual void func3() { cout << "TestA::func3(virtual)" << endl; }
public:
	int count;	
};


int main(void) {




	// if class has pure virtual function, the class is abstract class
	// can not be declare 'x' to TestA type
	TestA *x = NULL;
	x->func1();		//ok
	x->func2();		//error
	x->func3();		//error

	return 0;

}
