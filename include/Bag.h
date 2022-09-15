#pragma once
#include "vector.h"
#include <vector>

using namespace std;
template <typename Thing>
class Bag {
public:
	void insert(Thing aThing) {
		bagContents.push_back(aThing);
		bagSize++;
	}

	Thing& pop() {
		Thing aThing;
		if (bagContents.size() > 0) {
			aThing = bagContents[bagSize-1];
			bagSize--;
		}
		else {
			std::cerr << "Can't pop out of an empty bag" << std::endl;
		}
		return aThing;
	}

	int size() {
		return bagSize;
	}

	int count(Thing aThing) {
		int bagCount = 0;
		for (int i = 0; i < bagSize; ++i) {
			if (bagContents[i] == aThing) {
				bagCount++;
			}
		}
		return bagCount;
	}

	typedef Thing* iterator;
	typedef Thing* const_iterator;

	iterator begin() {
		return bagContents.begin();
	}

	iterator end() {
		return bagContents.end();
	}

	const_iterator begin() const {
		return bagContents.begin();
	}

	const_iterator end() const {
		return bagContents.end();
	}



private:
	vector<Thing> bagContents;
	int bagSize = 0;
};