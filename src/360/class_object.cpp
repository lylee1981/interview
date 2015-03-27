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
	virtual void func4() { cout << "TestA::func4(virtual)" << endl; }
	//virtual void func5() = 0;
public:
	int count;	
};

class TestASub : public TestA{
public:
	virtual void func5() {}
};


int main(void) {


	void (TestA::*vtl)();
	vtl = &TestA::func1;
	printf("TestA::func1 address: %p\n", vtl);

	TestA *x = NULL;
	x->func1();

	cout << "x address: " << x << endl;
	cout << "x v-table address: " << (int *)x << endl;
	return 0;


	/*

	// if class has pure virtual function, the class is abstract class
	// can not be declare 'x' to TestA type
	TestA x;
	x.func1();
	x.func2();
	x.func3();
	//x.func4();	//because of func4 is pure function, can not invoke x.func4()

	return 0;

	*/

	TestA a;

	//void (TestA::*vtl)();
	//vtl = &TestA::func2;
	//printf("TestA::func3 address: %p\n", vtl);
	//return 0;


	//TestA b;
	//TestASub sub;
	//return 0;

	cout << "a address: " << &a << endl;
	cout << "a v-table address: " << (int *)&a << endl;
	cout << "a v-table 's first v-func address: " << (int *)*(int *)&a << endl;
	cout << "a.count address: " << &(a.count) << endl;

	return 0;
	/*
	printf("member function func1 's address: %X\n", &TestA::func1);
	printf("member function TestA 's address: X\n", &TestA::TestA);
	printf("member function func2 's address: %X\n", &TestA::func2);
	printf("virtual member function func3 's address: %p\n", &TestA::func3);
	printf("virtual member function func4 's address: %p\n", &TestA::func4);
	*/
	//cout << "a.func3 address: " << &(a.func3) << endl;
	cout << "a.count address 's value: " << *(&(a.count)) << endl;
	cout << "sizeof(a) : " << sizeof(a) << endl;
	cout << "sizeof(TestA) : " << sizeof(TestA) << endl;


	a.func1();
	a.func2();
	a.func3();
	a.func4();
	//a->func4();

	//delete a;

	return 0;

}
