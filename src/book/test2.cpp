#include <iostream>

using namespace std;

int main() {

	int x=2, y, z;
	x*=(y=z=5);
	cout << x <<endl;

	z = 3;

	x == (y==z);

	cout << x <<endl;
	return 0;

}
