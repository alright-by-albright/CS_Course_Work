#include <iostream>
#include "CircularList.h"


using namespace std;

int main() {
	List<int> linkedListTest;
	linkedListTest.push_back(1);
	linkedListTest.push_back(2);
	linkedListTest.push_back(3);
	//List<int>* listPtr = nullptr;
	//const List<int>& listAlias = linkedListTest.back();
	//const int& intAlias = linkedListTest.back();
	//cout << intAlias << endl;

	CircularList<int> circularListTest;
	circularListTest.push_back(1);
	circularListTest.push_back(2);
	circularListTest.push_back(3);
	cout << circularListTest.front() << endl;
	circularListTest.pop_front();
	cout << circularListTest.front() << endl;
	circularListTest.correctEnds();
	circularListTest.traverse();


}