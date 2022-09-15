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
	/*void (*foo)(int);
	linkedListTest.traverse(foo);*/

	CircularList<int> circularListTest;
	circularListTest.push_back(1);
	circularListTest.push_back(2);
	circularListTest.push_back(3);
	circularListTest.correctEnds();
	circularListTest.traverse();


}