#include <Bag.h>
#include <iostream>

using namespace std;

int main() {
	Bag<int> bagTest;
	bagTest.insert(0);
	cout << "Successful insert" << endl;
	bagTest.insert(0);
	bagTest.insert(10);
	int zeroCount = bagTest.count(0);
	cout << "Succesful count " << zeroCount << endl;
	bagTest.pop();
	cout << "Succesful pop" << endl;
	zeroCount = bagTest.count(0);
	cout << "Succesful count " << zeroCount << endl;



	return 0;
}