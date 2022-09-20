#include <iostream>
#include "Tree.h"
using namespace std;

void printIt(int);

int main() {
	Tree<int> testTreeInt = { 0, 1, 2 };
	Tree<int>* testTree = new Tree<int>{ 0, 1, 2 };
	testTree->preorder(printIt);
	
	Tree<int>* tempTree = new Tree<int>{ testTree->left(), testTree->root(), testTree->right() };
	Tree<int>* testTreeCopy = new Tree<int>{ 0, 1, 2 };
	const auto* returnedTree = testTreeInt.deleteNode(testTreeInt, 2);

	testTreeCopy->preorder(printIt);


//	struct Node* tempNode = new Node{ leftVal, tempVal, rightVal };


	return 0;
}

void printIt(int data) {
	std::cout << data << std::endl;
}
