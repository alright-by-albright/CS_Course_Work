#include <Vector.h>
#include <iostream>

using namespace std;

int main() {
	Vector<int> testVector;
	cout << "push_back test " << endl;
	for (int i = 0; i < 10; i++) {
		testVector.push_back(i);
	}
	for (int i = 0; i < testVector.size(); i++) {
		cout << testVector[i] << endl;
	}
	Vector<int> copyVector = testVector;
	cout << "deep copied vector test" << endl;
	for (int i = 0; i < copyVector.size(); i++) {
		cout << copyVector[i] << endl;
	}
	copyVector.pop_back();
	cout << "Succesful pop from copy" << endl;
	cout << "Checking that original vector not affected by copy pop" << endl;
	cout << copyVector[copyVector.back()] << endl;
	cout << testVector[testVector.back()] << endl;
	cout << endl << "Iterator test" << endl;
	for (auto iterator : testVector) {
		cout << iterator << endl;
	}

	return 0;
}