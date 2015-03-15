/*
Manager: Wolfgang C. Strack

This file includes the implementation for:
- DoublyLinkedList class
*/

#pragma once

#include "Global.h"

// ---------------------- DoublyLinkedList Class Interface ----------------------------------------
// Doubly Linked List abstract base class
// By C. Lee-Klawender

// Modified by: Wolfgang C. Strack
/* Modifications:
- completed Destructor
- clear() uses a while loop instead of a for loop
*/

// Implementation: SAList.cpp

template<class ItemType>
class DoublyLinkedList
{
protected:
	Node<ItemType>* headPtr; // Pointer to (dummy) first node in the list
	Node<ItemType>* tailPtr; // Pointer to (dummy) last node in the list
	int itemCount;           // Current count of list items
public:
	// constructor
	DoublyLinkedList();
	// copy constructor
	DoublyLinkedList(const DoublyLinkedList<ItemType>& aList);
	// destructor
	virtual ~DoublyLinkedList()	{ clear(); delete headPtr; delete tailPtr; }

	// check for empty list
	bool isEmpty() const	{ return (itemCount == 0); }
	// get number of entries in the list
	int size() const		{ return itemCount; }
	// remove all entries from list
	void clear();
	// display list from front to end
	void display() const;
	// abstract insert function
	virtual bool insert(const ItemType& newEntry, int newPosition = 1) = 0;
};
// ---------------------- DoublyLinkedList Class Interface End ------------------------------------

// ---------------------- DoublyLinkedList Class Implementation -----------------------------------
/*
Modifications:
- completed Destructor
- clear() uses a while loop instead of a for loop
*/
template<class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList()
{
	itemCount = 0;
	headPtr = new Node<ItemType>();
	tailPtr = new Node<ItemType>();
	headPtr->setNext(tailPtr);
	tailPtr->setPrev(headPtr);
}

template<class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList<ItemType>& aList)
{
	itemCount = aList.itemCount;
	Node<ItemType>  *origChainPtr;

	origChainPtr = aList.headPtr;

	headPtr = new Node<ItemType>();				// copy dummy head node

	// Copy remaining nodes BEFORE tailPtr
	Node<ItemType>* newChainPtr = headPtr;		// ignore data
	origChainPtr = origChainPtr->getNext();
	while (origChainPtr != aList.tailPtr)
	{
		ItemType *nextItem = origChainPtr->getItem();
		Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
		newChainPtr->setNext(newNodePtr);		// link prev to current
		newNodePtr->setPrev(newChainPtr);		// link current to prev

		newChainPtr = newChainPtr->getNext();
		origChainPtr = origChainPtr->getNext();
	}
	// Create tail and init. prev
	tailPtr = new Node<ItemType>();
	tailPtr.setPrev(newChainPtr);
	newChainPtr->setNext(tailPtr);
}



template<class ItemType>
void DoublyLinkedList<ItemType>::display() const
{
	Node<ItemType>* currPtr = headPtr->getNext();
	while (currPtr != tailPtr)
	{
		cout << currPtr->getItem() << " ";		// display data
		currPtr = currPtr->getNext();			// go to next node
	}
	cout << endl << endl;
}


template<class ItemType>
void DoublyLinkedList<ItemType>::clear()
{
	Node<ItemType> * deletePtr, *nodePtr;
	deletePtr = headPtr->getNext();
	nodePtr = deletePtr;
	while (nodePtr != tailPtr)					// walk each node
	{
		nodePtr = deletePtr->getNext();
		delete deletePtr;
		deletePtr = nodePtr;
	}

	itemCount = 0;
}
// ---------------------- DoublyLinkedList Class Implementation End -------------------------------