#include <iostream>
#include "Tree.h"
using namespace std;

void printIt(int);

int main() {
	Tree<int>* testTree = new Tree<int>{ 0, 1, 2 };
	testTree->preorder(printIt);

	auto tempVal = testTree->root();
	auto leftVal = testTree->right();
	auto rightVal = testTree->left();

//	struct Node* tempNode = new Node{ leftVal, tempVal, rightVal };


	return 0;
}

void printIt(int data) {
	std::cout << data << std::endl;
}
