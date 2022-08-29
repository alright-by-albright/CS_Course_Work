#pragma once
#include<vector>
#include <map>
#include <iostream>

using namespace std;
template<typename Thing>
class ReceiptBag {
public:
	void insert(Thing aThing) {
		receiptBagContents.push_back(aThing);
		cout << aThing << " inserted into bag at index " << bagSize << ".\n" << endl;
		bagSize += 1;
		receiptBagIndex.push_back(bagSize);
	}

	int remove_item(const int& index) {
		if (bagSize == 0) {
			cerr << "You can't remove an item from an empty bag :: cerr\n" << endl;
		}
		if (index > bagSize) {
			cerr << "Index value exceeds item count. Please check the index value entered.\n" << endl;
		}
		else {
			Thing aThing = receiptBagContents[index];
			receiptBagContents.erase(receiptBagContents.begin() + index);
			receiptBagIndex.pop_back();
			bagSize--;
			cout << "Item " << aThing << " at index " << index << " removed.\n" << endl;
			return bagSize;
		}
	}

	int remove_item(const Thing& aThing) {
		int index = 0, startingSize = bagSize;
		if (bagSize == 0) {
			cerr << "You can't remove an item from an empty bag :: cerr\n" << endl;
		}
		for (auto const& x : receiptBagContents) {
			if (x == aThing) {
				receiptBagContents.erase(receiptBagContents.begin() + index);
				receiptBagIndex.pop_back();
				bagSize--;
				cout << aThing << " removed from index slot " << index << ".\n" << endl;
				return bagSize;
			}
			else index++;
		}
		if (startingSize = bagSize) {
			cout << "Item not found, removal failed.\n" << endl;
		}
	}

	Thing& operator[](int index) {
		if (index < bagSize) {
			cout << "You have a " << receiptBagContents[index] << " in your bag at index slot " << index << ".\n" << endl;
		}
		return receiptBagContents[index];
	}

	void traverseReceiptBag() {
		for (int i = 0; i < receiptBagContents.size(); i++) {
			cout << receiptBagContents[i] << " : " << i << endl;
		}
	}

	int size() {
		return bagSize;
	}

	int begin() {
		return bagSize;
	}

	int end() {
		return receiptBagContentsMap.end();
	}

	//~ReceiptBag() {
	//	delete receiptBagContentsMap;
	//	delete receiptBagContents;
	//}

private:
	vector<Thing> receiptBagContents;
	vector<int> receiptBagIndex;
	map<int, Thing> receiptBagContentsMap;
	int bagSize = 0;
};