#pragma once
#include <functional>
template <typename T>
class List {
private:
	class Node {
	public:
		T data;
		Node* prev;
		Node* next;
		bool isHiddenNode = false;
	};
	Node* head;
	Node* tail;

public:
	class const_iterator {
	protected:
		Node* current;

		T& retrieve() const { return current->data;  }

		const_iterator(Node* p) : current(p) { }

		void assertIsValid() const
		{
			if (current == nullptr || head == nullptr) throw IteratorOutOfBoundsException{ };
		}

		friend class List<T>;
	public:
		const_iterator() : current(nullptr) { }

		T& operator*() const {
			return retrieve();
		}

		const_iterator& operator++() {
			current = current->next;
			return *this;
		}

		const_iterator operator++(int) {
			const_iterator old = *this;
			++(*this);
			return old;
		}

		const_iterator& operator--() {
			current = current->prev;
			return *this;
		}

		const_iterator operator--(int) {
			const_iterator old = *this;
			--(*this);
			return old;
		}

		bool operator==(const const_iterator& rhs) const {
			return current == rhs.current;
		}

		bool operator!=(const const_iterator& rhs) const {
			return !(*this == rhs);
		}

		};

	class iterator : public const_iterator {
	protected:
		iterator(Node *p) : const_iterator(p) { }
		friend class List<T>;

	public:
		iterator() { }

		T& operator*() {
			return const_iterator::retrieve();
		}

		const T& operator* () const {
			return const_iterator::operator*();
		}

		iterator& operator++ () {
			this->current = const_iterator::current->next;
			return *this;
		}

		iterator operator++ (int) {
			iterator old = *this;
			++(*this);
			return old;
		}

		iterator& operator-- () {
			this->current = const_iterator::current->prev;
			return *this;
		}

		iterator operator-- (int) {
			iterator old = *this;
			--(*this);
			return old;
		}

	};

private:
	void setUpList() {
		Node* newNode = new Node();
		newNode->next = tail;
		newNode->prev = head;
		head->next = newNode;
		tail->prev = newNode;
	}

	void deleteListContents() {
		Node* current = head->next;
		Node* temp = nullptr;
		while (current != tail->prev) {
			temp = current->next;
			delete current;
			current = temp;
		}
	}

public:
	List() {
		head = new Node();
		head->isHiddenNode = true;
		tail = new Node();
		tail->isHiddenNode = true;
		head->prev = nullptr;
		head->next = tail;
		tail->prev = head;
		tail->next = nullptr;
	}

	List(T newData) {
		setupList();
		(head->next)->data = newData;
	}

	List(List& rhs) {
		// copy constructor
		deleteListContents();
		head = rhs.head;
		tail = rhs.tail;
	}

	~List() {
		// And a destructor
		deleteListContents();
		delete head;
		delete tail;
	}
	
	bool empty() {
		return (head->next == tail);
	}

	//iterator related methods
	iterator begin() { return { head->next }; }

	iterator end() { return { tail }; }

	const_iterator cbegin() const {
		return { head->next };
	}

	const_iterator cend() const
		{ return { tail }; }

	iterator rbegin() { return { tail->prev }; }

	iterator rend() { return { head }; }

	const_iterator crbegin() const {
		return { tail->prev };
	}

	const_iterator crend() const {
		return { head };
	}

	// and the methods for the rest
	void push_front(T data) {
		if (this->empty()) {
			setUpList();
			Node* actualHead = head->next;
			actualHead->data = data;
		}
		else {
			Node* actualHead = head->next;
			Node* newNode = new Node();
			newNode->data = data;
			newNode->next = actualHead;
			actualHead->prev = newNode;
			newNode->prev = head;
			head->next = newNode;
		}
	}

	void push_back(T data) {
		if (this->empty()) {
			setUpList();
			Node* actualTail = tail->prev;
			actualTail->data = data;
		}
		else {
			Node* actualTail = tail->prev;
			Node* newNode = new Node();
			newNode->data = data;
			newNode->prev = actualTail;
			actualTail->next = newNode;
			newNode->next = tail;
			tail->prev = newNode;
		}
	}

	T& front() {
		Node* actualHead = head->next;
		return (actualHead->data);
	}

	T& back() {
		Node* actualTail = tail->prev;
		return(actualTail->data);
	}

	void pop_back() {
		Node* lastNode = tail->prev;
		tail->prev = lastNode->prev;
		Node* newLastNode = tail->prev;
		newLastNode->next = tail;
		delete lastNode;
		lastNode = nullptr;
	}

	void pop_front() {
		Node* firstNode = head->next;
		head->next = firstNode->next;
		Node* newFirstNode = head->next;
		newFistNode->prev = head;
		delete firstNode;
		firstNode = nullptr;
	}

	void traverse(std::function<void(T& data)> doIt) {
		Node* current = head->next;
		while (current != tail) {
			doIt(current->data);
			current = current->next;
		}
	}

	void reverse_traverse(std::function<void(T& data)> doIt) {
		Node* current = tail->prev;
		while (current != head) {
			doIt(current->data);
			current = current->prev;
		}
	}

	//Insert data before iter.
	iterator insert(iterator iter, const T& data)
	{
		Node* p = iter.current;
		return { p->prev = p->prev->next = new Node{data, p->prev, p} };
	}

	//Insert data before iter
	iterator insert(iterator iter, T& data)
	{
		Node* p = iter.current;
		return { p->prev = p->prev->next = new Node{ std::move(data), p->prev, p} };
	}

	//Erase item at iter.
	iterator erase(iterator iter)
	{
		Node* p = iter.current;
		iterator retVal{ p->next };
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
		
		return retVal;
	}

	iterator erase(iterator from, iterator to)
	{
		for (iterator iter = from; iter != to;)
			iter = erase(iter);

		return to;
	}
};