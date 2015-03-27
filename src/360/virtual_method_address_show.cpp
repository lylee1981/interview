#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;


class Base {
public:
	virtual void func() { cout << "v-func1 invoke" << endl; }
	virtual void func2() { cout << "v-func2 invoke" << endl; }
	Base() {
		cout << "Base Constructor" << endl;
	}
	virtual ~Base() {
	
		cout << "Base Destructor" << endl;
	}
};


int main(void) {

	typedef void(*Fun)(void);

	Fun pFun = NULL;

	Base b;

	cout << "object b 's base address: " << &b << endl;
	cout << "class Base 1 v-func 's address: " << (int*)*(int*)&b << endl;
	cout << "class Base 2 v-func 's address: " << (int*)*(int*)&b + 1 << endl;
	cout << "class Base 2 v-func 's address: " << (int*)*(int*)&b + 2 << endl;


	cout << "class Base 1 v-func 's value: " << (Fun)*(int*)*(int*)&b << endl;
	cout << "class Base 2 v-func 's value: " << (Fun)*((int*)*(int*)&b + 1) << endl;

	pFun = (Fun)(*((int*)*(int*)&b));
	pFun();

	
	pFun = (Fun)(*((int*)*(int*)&b + 1));
	pFun();

	//pFun = (Fun)(*((int*)*(int*)&b + 2));
	//pFun();

	return 0;

}
