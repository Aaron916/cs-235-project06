#ifndef NODE_H
#define NODE_H

#include <iostream>

template <class T>
struct Node {
public:
	T data;
	Node<T>* pNext;
	Node<T>* pPrev;

	Node()
	{
		pNext = NULL;
		pPrev = NULL;
	}

	Node(T t)
	{
		data = t;
		pNext = NULL;
		pPrev = NULL;
	}

};

template <class T>
Node <T>* copy(Node<T>* pSource) // removed the const before the argument to test a fix for an error.
{
	Node<T> *pDestination = new Node<T>(pSource->data);
    Node<T> *pSrc = pSource;
	Node<T> *pDes = pDestination;

	while (pSrc->pNext)
	{
		pDes = insert(pDes, pSrc->data, true);
	}
	return pDestination;
}

template <class T>
Node <T>* insert(Node<T> *pCurrent, const T &t, bool after = false)
{
	Node<T>* pNew = new Node<T>;

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
	while (pHead->pNext)
	{
		pHead->data = t;
		return pHead;
	}
	return NULL;
}

template <class T>
void freeData(Node<T>* & pHead)
{
	while (pHead)
	{
		Node<T>* pDelete = pHead;
		pHead = pHead->pNext;
		delete pDelete;
	}
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

template <class T>
std::ostream& operator << (std::ostream& out, const Node<T>* list)
{
	if (list)
	{
		out << list->data;
	}
	return out;
}
#endif // NODE_H
