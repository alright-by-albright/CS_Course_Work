#include <iostream>
#include <chrono>
#include <vector>
#include "Vector.h"

using namespace std;

class vectorTesting
{
public:
	void createSTLVectorTest() {
		fillSTLVectorTest(stlVectorTest);
	}
	void createMYVectorTest() {
		fillMyVectorTest(myVectorTest);
	}

	void addToFullSTLVectorTest(int num) {
		auto start = std::chrono::steady_clock::now();
		cout << "My stl vector size " << stlVectorTest.capacity() << endl;
		fillSTLVectorTest(stlVectorTest);
		stlVectorTest.push_back(num);
		auto end = std::chrono::steady_clock::now();
		auto elapsed_seconds = end - start;
		cout << "New vector size " << stlVectorTest.capacity() << endl;
		cout << "Time to add to full stl vector " << elapsed_seconds.count() << endl;
	}

	void addToFullMyVectorTest(int num) {
		auto start = std::chrono::steady_clock::now();
		cout << "My Vector size " << myVectorTest.size() << endl;
		fillMyVectorTest(myVectorTest);
		myVectorTest.push_back(num);
		auto end = std::chrono::steady_clock::now();
		auto elapsed_seconds = end - start;
		cout << "New vector size " << myVectorTest.size() << endl;
		cout << "Time to add to full Vector " << elapsed_seconds.count() << endl;
	}
private:
	vector<int> stlVectorTest;
	Vector<int> myVectorTest;

	void fillSTLVectorTest(vector<int>& stlVectorTest) {
		int stlCapacity = stlVectorTest.capacity();
		// Using emplace_back to avoid creating a copy and directly adding i to the stl vector is 
		// slightly faster, but even push_back is faster than using a similar push_back with the Vector.h
		// vector.
		// for (int i = 0; i < stlCapacity; i++) stlVectorTest.emplace_back(i);
		for (int i = 0; i < stlCapacity; i++) stlVectorTest.push_back(i);
		stlVectorTest.push_back(1);
	}

	void fillMyVectorTest(Vector<int>& myVectorTest) {
		cout << "Starting stats: " << myVectorTest.capacity() << " " << myVectorTest.size() << endl;
		int myCapacity = myVectorTest.capacity();
		for (int i = 0; i < myCapacity; i++) myVectorTest.push_back(i);
		myVectorTest.push_back(1);
	}
};

int main() {
	vectorTesting vectorTest;
	vectorTest.createSTLVectorTest();
	vectorTest.createMYVectorTest();

	for (int i = 0; i < 10; i++) {
		vectorTest.addToFullSTLVectorTest(1);
		cout << endl << endl;
		vectorTest.addToFullMyVectorTest(1);
		cout << endl << endl;
	}

}