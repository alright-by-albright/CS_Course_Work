#include <iostream>
#include "Tree.h"
using namespace std;

void printIt(int);

int main() {
	Tree<int>* testTree = new Tree<int>{ 0, 1, 2 };
	testTree->preorder(printIt);



	return 0;
}

void printIt(int data) {
	std::cout << data << std::endl;
}
