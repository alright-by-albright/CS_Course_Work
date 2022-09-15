#pragma once
#include <functional>
#include "LinkedList.h"

template <typename T>
class CircularList : public List<T> {
public:
	// Adding a function to correct the ends of the linked list so they correctly feed into one another.	
	void correctEnds() {
		Node* current = head;
		current->prev = tail;
		current = current->prev;
		current->next = head;
	}

	// Redefining the virtual traverse function so that it will accept a starting point, then loop around and
	// back to said point before stopping. Otherwise it just runs forever.
	void traverse() {
		Node* temp = head->next;
		Node* start = head->next;
		if (head != NULL)
		{
			do
			{
				cout << temp->data << " ";
				temp = temp->next;
			} while (temp != start);
		}
	}

	//void circle()
	
};