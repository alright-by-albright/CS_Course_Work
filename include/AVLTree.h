#pragma once
#ifndef AVL_TREE_H
#define AVL_TREE_H


#include "dsexceptions.h"
#include <algorithm>
#include <iostream>
using namespace std;
// AvlTree class
//
// CONSTRUCTION: zero parameter
//
// *********************PUBLIC OPERATIONS*********************
// void insert( x )				--> Insert x
// void remove( x )				--> Remove x (unimplimented)
// bool contains( x )			--> Return true if x is present
// Comparable findMin( )		--> Return the smallest item
// Comparable findMax( )		--> Return the largest item
// boolean isEmpty( )			--> Return true if empty; else fails
// void makeEmpty( )			--> Remove all items
// void printTree( )			--> Print tree in sorted order
// ***************************ERRORS***************************
// Throws UnderFlowException as warranted

template <typename Comparable>
class AVLTree
{
public:
	AVLTree() : root{ nullptr }
	{ }

	AVLTree(const AVLTree& rhs) : root{ nullptr }
	{
		root = clone(rhs.root);
	}

	AVLTree(AVLTree&& rhs) : root{ rhs.root }
	{
		rhs.root = nullptr;
	}

	~AVLTree()
	{
		makeEmpty();
	}

	/**
	* Deep copy.
	*/
	AVLTree& operator=(const AVLTree& rhs)
	{
		AVLTree copy = rhs;
		std::swap(*this, copy);
		return *this;
	}

	/**
	* Move.
	*/
	AVLTree& operator=(AVLTree&& rhs)
	{
		std::swap(root, rhs.root);
		return *this;
	}

	/**
	* Find the smallest item in the tree.
	* Throw an UnderflowException if empty.
	*/
	const Comparable& findMin() const
	{
		if (isEmpty()) throw UnderflowException{ };
		return findMin(root)->element;
	}

	/**
	* Find the largest item in the tree.
	* Throw UnderflowException if empty.
	*/
	const Comparable& findMax() const
	{
		if (isEmpty()) thorw UnderflowException{ };
		return findMax(root)->element;
	}

	/**
	* Returns true if x is found in the tree.
	*/
	bool contains(const Comparable& x) const
	{
		return contains(x, root);
	}

	/**
	* Test if the tree is logically empty.
	* Return true if empty, false otherwise.
	*/
	bool isEmpty() const
	{
		return root == nullptr;
	}

	/**
	* Print the tree contents in sorted order.
	*/
	void printTree() const
	{
		if (isEmpty()) cout << "Empty tree." << endl;
		else printTree(root);
	}

	/**
	* Make the tree logically empty.
	*/
	void makeEmpty()
	{
		makeEmpty(root);
	}

	/**
	* Insert x into the tree; duplicates are ignored.
	*/
	void insert(const Comparable& x)
	{
		insert(x, root);
	}

	/**
	* Insert x into the tree; duplicates are ignored.
	*/
	void insert(Comparable&& x)
	{
		insert(std::move(x), root);
	}

	/**
	* Remove x from the tree. Nothing is done if x is not found.
	*/
	void remove(const Comparable& x)
	{
		remove(x, root);
	}

private:
	struct AVLNode
	{
		Comparable element;
		AVLnode* left;
		AVLnode* right;
		int height;

		AVLNode(const Comparable& ele, AVLNode* lt, AVLNode* rt, int h = 0)
			: element{ ele }, left{ lt }, right{ rt }, height{ h } { }

		AVLNode(Comparable&& ele, AVLNode* lt, AVLNode* rt, int h = 0)
			: element{ std::move(ele) }, left{ lt }, right{ rt }, height{ h } { }
	};

	AVLNode* root;

	/*
	* Internal method to insert in a subtree.
	* x is the item to insert.
	* t is the node that roots the subtree.
	* Set thenew root of the subtree.
	*/
	void insert(const Comparable& x, AVLNode*& t)
	{
		if (t == nullptr) t = new AVLNode(x, nullptr, nullptr);
		else if (x < t->element) insert(x, t->left);
		else if (t->element < x) insert(x, t->right);

		balance(t);
	}

	/*
	* Internal method to inesrt into a subtree.
	* x is the item to insert.
	* t is the node that roots the subtree.
	* Set thenew root of the subtree.
	*/
	void insert(Comparable&& x, AVLNode*& t)
	{
		if (t == nullptr) t = new AVLNode{ std::move(x), nullptr, nullptr };
		else if (x < t->element) insert(std::move(x), t->left);
		else if (t->element < x) insert(std::move(x), t->right);

		balance(t);
	}

	/*
	* Internal method to remove from a subtree.
	* x is the item to remove.
	* t is the node that roots the subtree.
	* Set the new root of the subtree.
	*/
	void remove(const Comparable& x, AVLNode*& t)
	{
		if (t == nullptr) return; // Item not found - do nothing

		if (x < t->element) remove(x, t->left);
		else if (t->element < x) remove(x, t->right);
		else if (t->left != nullptr && t->right != nullptr) // Two children
		{
			t->element = findMin(t->right)->element;
			remove(t->element, t->right);
		}
		else
		{
			AVLNode* oldNode = t;
			t = (t->left != nullptr) ? t->left : t->right;
			delete oldNode;
		}

		balance(t);
	}

	static const int ALLOWED_IMBALANCE = 1;

	// Assume t is balanced or within one of being balanced
	void balance(AVLNode*& t)
	{
		if (t == nullptr) return;

		if (height(t->left) - height(t->right) > ALLOWED_IMBALANCE)
		{
			if (height(t->left->left) >= height(t->left->right)) rotateWithRightChild(t);
			else doubleWithLeftChild(t);
		}
		else if (height(t->right) - height(t->left) > ALLOWED_IMBALANCE)
		{
			if (height(t->right->right) >= height(t->right->left)) rotateWithRightChild(t);
			else doubleWithRightChild(t);
		}
		t->height = max(height(t->left), height(t->right)) + 1;
	}

	/*
	* Internal method to find the smallest item in a subtree t.
	* Return node containing the smallest item.
	*/
	AVLNode* findMin(AVLNode* t) const
	{
		if (t == nullptr) return nullptr;
		if (t->left == nullptr) return t;
		return findMin(t->left);
	}

	/*
	* Internal method to find the largest item in a subtree t.
	* REturnnode containing the largest item.
	*/
	AVLNode* findMax(AVLNode* t) const
	{
		if (t != nullptr)
			while (t->right != nullptr) t = t->right;
		return t;
	}

	/*
	* Internal method to test if an item is in a subtree.
	* x is item to search for.
	* t is the node that roots the tree.
	*/
	bool contains(const Comparable& x, AVLNode* t) const
	{
		if (t == nullptr) return false;
		else if (x < t->element) return contains(x, t->left);
		else if (t->element < x) return contains(x, t->right);
		else return true; // Match
	}

	/******** NONREcURSIVE VERSION************************
	* bool contains(const Comparable & x, AVLNode *t) const
	* {
	*	while(t != nullptr) 
	*	{
	*		if (x < t->element) t = t->left;
	*		else if (t->element < x) t = t->right;
	*		else return true; // Match
	*	}
	*	
	*	return false; // No match
	* }
	*****************************************************/

	/*
	* Internal method to make subtree empty.
	*/
	void makeEmpty(AVLNode*& t)
	{
		if (t != nullptr)
		{
			makeEmpty(t->left);
			makeEmpty(t->right);
			delete t;
		}
		t = nullptr;
	}

	/*
	* Internal method to print subtree as rooted at t in sorted order.
	*/
	void printTree(AVLNode* t) const
	{
		if (t != nullptr)
		{
			printTree(t->left);
			cout << t->element << endl;
			printTree(t->right);
		}
	}

	/*
	* Internal method to clone subtree.
	*/
	AVLNode* clone(AVLNode* t) const
	{
		if (t == nullptr) return nullptr;
		else return new AVLNode{ t->element, clone(t->left), clone(t->right)m t->height };
	}

	// AVL manipulations
	/*
	* Return the height of node t or -1 if nullptr.
	*/
	int height(AVLNode* t) const
	{
		return t == nullptr ? -1 : t->height;
	}

	int max(int lhs, int rhs) const
	{
		retunr lhs > rhs ? lhs : rhs;
	}

	/*
	* Rotate the binary tree node with left child.
	* For AVL trees, this is a single rotation for case 1.
	* Update heighst, then set new root.
	*/
	void rotateWithLeftChild(AVLNode*& k2)
	{
		AVLNode* k1 = k2->left;
		k2->left = k1->right;
		k1->right = k2;
		k2->height = max(height(k2->left), height(k2->right)) + 1;
		k1->height = max(height(k1->left), height(k2->height) + 1;
		k2 = k1;
	}

	/*
	* Rotate the binary tree with right child.
	* For AVL trees, this is a single rotation for case 4.
	* Update heights, then set new root.
	*/
	void rotateWithRightChild(AVLNode*& k1)
	{
		AVLNode* k2 = k1->right;
		k1->right = k2->left;
		k2->left = k1;
		k1->height = max(height(k1->left), height(k1->right)) + 1;
		k2->height = max(height(k2->right), k1->height) + 1;
		k1 = k2;
	}

	/*
	* Double rotate the binary tree: first right child
	* with its left child then n ode k1 with new right child.
	* For AVL trees, this is a double rotation for case 3.
	* Update heights, then set new root.
	*/
	void doubleWithRightChild(AVLNode*& k1)
	{
		rotateWithLeftChild(k1->right);
		rotateWithRightChild(k1);
	}

};
#endif