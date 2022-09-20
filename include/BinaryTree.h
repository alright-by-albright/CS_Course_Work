#pragma once

#include <iostream>
using namespace std;

template <class T>
struct BstNode {
	T data;
	BstNode* left;
	BstNode* right;
};

void Insert(BstNode* root, int data);

int main() {
	BstNode* root = nullptr;
}

