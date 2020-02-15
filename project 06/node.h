#ifndef NODE_H
#define NODE_H

#include <iostream>

template <class T>
struct Node {
public:
	T data;
	Node<T>* pNext;
	Node<T>* pPrev;

	Node() : pNext(NULL), pPrev(NULL), data() {}

	// non-default. Initialize data as we create the node
	Node(const T& data) : pNext(NULL), pPrev(NULL), data(data) {} // changed the format of the constructors to be in line with what the instructor has. -AG
};

template <class T>
Node <T>* copy(Node<T>* pSource) // removed the const before the argument to test a fix for an error.
{
	Node<T>* pDestination = new Node<T>(pSource->data);
	Node<T>* pSrc = pSource;
	Node<T>* pDes = pDestination;

	for (Node<T>* p = pSource; p != NULL; p = p->pNext) // Had to change the loop. It wasn't copying correctly. It was throwing bad_alloc exceptions. -AG
	{
		pDes = insert(pDes, pSrc->data, true);
	}
	return pDestination;
}

template <class T>
Node <T>* insert(Node<T>*& pCurrent, const T& t, bool after = false)
{
	Node<T>* pNew = new Node<T>(t);

	if (pCurrent && after == false)
	{
		pNew->pNext = pCurrent;
		pNew->pPrev = pCurrent->pPrev;
		pCurrent->pPrev = pNew;
		if (pNew->pPrev)
		{
			pNew->pPrev->pNext = pNew;
		}
	}

	if (pCurrent && after == true)
	{
		pNew->pPrev = pCurrent;
		pNew->pNext = pCurrent->pNext;
		pCurrent->pNext = pNew;
		if (pNew->pNext)
		{
			pNew->pNext->pPrev = pNew;
		}
	}

	return pNew;
}

template <class T>
Node <T>* find(Node<T>* pHead, const T& t)
{
	// Changed the contents of this function to what the instructor posted in the discussion board. -AG
	// loop through the linked list
	for (Node <T>* p = pHead; p != NULL; p = p->pNext)
		if (t == p->data)
			return p;

	return NULL;
}

template <class T>
void freeData(Node<T>*& pHead)
{
	// Changed the contents of this function to what the instructor posted in the discussion board. -AG
	Node <T>* pNext;
	for (Node <T>* p = pHead; p; p = pNext)
	{
		pNext = p->pNext;
		delete p;
	}
	pHead = NULL;
}

template <class T>
Node <T>* remove(const Node<T>* pRemove)
{
	if (NULL == pRemove)
		return NULL; // added NULL because we needed to return some value. //

	Node<T>* pReturn = NULL; // Initialized to NULL so that there was no case in which it could return an unititialized value //

	if (pRemove->pPrev)
	{
		pRemove->pPrev->pNext = pRemove->pNext;
		pReturn = pRemove->pPrev;
	}
	if (pRemove->pNext)
	{
		pRemove->pNext->pPrev = pRemove->pPrev;
		pReturn = pRemove->pNext;
	}

	delete pRemove;
	return pReturn;
}

//changed this operator overload method to what the instructor shared in the discussion board.
template <class T>
std::ostream& operator << (std::ostream& out, const Node <T>* pHead)
{
	// paranoia
	if (pHead == NULL)
		return out;

	// display the data
	out << pHead->data;

	// if there is something after us, display it
	if (pHead->pNext)
		return out << ", " << pHead->pNext;
	else
		return out;
}

/******************************************************
* FIND SORTED
* Find the spot in a given linked list where a given Node
* is to go. We will return a pointer to the node preceeding
* one where the new node will exist in the list
* INPUT : a pointer to the head of the linked list
* the value we are inserting
* OUTPUT : a pointer to the node we will be inserting after
* COST : O(n)
********************************************************/
template <class T> // Added this function from the instructor's post in the discussion board.
Node <T>* findSorted(Node <T>* pHead,
	const T& t)
{
	// trivial case
	if (NULL == pHead || t < pHead->data)
		return NULL;

	// search for the node
	while (pHead->pNext && pHead->pNext->data < t)
		pHead = pHead->pNext;

	return pHead;
}


#endif // NODE_H
