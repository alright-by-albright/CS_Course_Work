#include "ReceiptBag.h"
#include <iostream>

using namespace std;

int main() {
	ReceiptBag<string> receiptBagTest;
	string userDefinedItem;
	int userDefinedIndex, newUserVectType;
	cout << "New bag created! Please note that all index slot values are offset by 1 for readability.\n";
	string userItem = "cereal";
	receiptBagTest.insert(userItem);
	receiptBagTest[0];
	cout << "Enter a string item to add to the receipt bag.\n";
	cin >> userDefinedItem;
	cin.clear();
	receiptBagTest.insert(userDefinedItem);
	cout << "Enter an index between 0 and " << receiptBagTest.size()-1 << " to remove from the receipt bag.\n";
	cin >> userDefinedIndex;
	cin.clear();
	receiptBagTest.remove_item(userDefinedIndex);
	cout << "Re-Adding removed item for testing\n";
	receiptBagTest.insert(userDefinedItem);
	cout << "Enter the name of an item for removal. Items in bag are: \n";
	receiptBagTest.traverseReceiptBag();
	cout << endl << "Enter the name of an item to remove.\n";
	cin >> userDefinedItem;
	receiptBagTest.remove_item(userDefinedItem);
	
	return 0;
}