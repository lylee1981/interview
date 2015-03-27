#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;


class Base {
public:
	virtual void func() = 0;
	virtual void func2() { cout << "v-func2 invoke " << endl; }
	Base() {
		cout << "Base Constructor" << endl;
	}
	virtual ~Base() {
	
		cout << "Base Destructor" << endl;
	}
};


int main(void) {

	//because of Base has pure virtual method, so can not has Base type 's object
	//Base b;		//error

	Base *b = new Base;		// error again

	return 0;

}
