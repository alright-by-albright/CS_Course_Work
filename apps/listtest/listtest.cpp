//
// File: listtest.cpp
// Author: Your Glorious Instructor <adam.lewis@athens.edu>
// Purpose:
// Demonstrate the use of our List class.
//
#include <iostream>
#include "LinkedList.h"

void printItem(int& item) {
	std::cout << item << " ";
}

int main() {
	List<int> aListOfIntegers;
	if (aListOfIntegers.empty()) {
		std::cout << "Yep, the new list is empty." << std::endl;
	}
	for (int i = 3; i >= 0; i--) {
		aListOfIntegers.push_front(i);
	}
	aListOfIntegers.traverse(printItem);
	std::cout << std::endl;

	std::cout << "Test iterators: Mutable-> ";
	for (auto iter = aListOfIntegers.begin();
		iter != aListOfIntegers.end();
		++iter) {
		std::cout << *iter << " ";
	}
	std::cout << std::endl;

	std::cout << "Test iterators: const-> ";
	for (auto iter = aListOfIntegers.cbegin();
		iter != aListOfIntegers.cend();
		++iter) {
		std::cout << *iter << " ";
	}
	std::cout << std::endl;

	std::cout << "Test back: ";
	for (int i = 0; i < 3; i++) {
		int datum = aListOfIntegers.back();
		std::cout << datum << " ";
		aListOfIntegers.pop_back();
	}
	std::cout << std::endl;

	std::cout << "Test push_front: ";
	for (int i = 1; i <= 3; i++) {
		aListOfIntegers.push_back(i);
	}
	std::cout << "Complete" << std::endl;

	std::cout << "Test traverse: ";
	if (!aListOfIntegers.empty()) {
		aListOfIntegers.traverse(printItem);
	}
	std::cout << std::endl;

	std::cout << "Test push_back value 42, traverse called on passed value: ";
	aListOfIntegers.push_back(42);
	aListOfIntegers.traverse(printItem);
	std::cout << std::endl;

	std::cout << "Test reverse traversal: ";
	for (auto iter = aListOfIntegers.rbegin();
		iter != aListOfIntegers.rend();
		iter--) {
		std::cout << *iter << " ";
	}
	std::cout << std::endl;

	std::cout << "Test insertion of value 5 before 2: ";
	for (auto iter = aListOfIntegers.begin();
		iter != aListOfIntegers.end();
		++iter) {
		if (*iter == 2) {
			aListOfIntegers.insert(iter, 5);
		}
	}
	for (auto iter = aListOfIntegers.begin();
		iter != aListOfIntegers.end();
		++iter) {
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
	
	std::cout << "Testing erasure of value 5: ";
	for (auto iter = aListOfIntegers.begin();
		iter != aListOfIntegers.end();
		++iter) {
		if (*iter == 5) {
			aListOfIntegers.erase(iter);
			break;
		}
	}
	for (auto iter = aListOfIntegers.begin();
		iter != aListOfIntegers.end();
		++iter) {
		std::cout << *iter << " ";
	}
	std::cout << std::endl;

	return 0;
}