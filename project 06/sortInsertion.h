/***********************************************************************
 * Header:
 *    INSERTION SORT
 * Summary:
 *    This will contain just the prototype for insertionSortTest(). You may
 *    want to put other class definitions here as well.
 * Author
 *    Adam Goff, Martin Melerio, Aaron Rooks, Tanner Stratford
 ************************************************************************/

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "node.h"

 /***********************************************
  * INSERTION SORT
  * Sort the items in the array
  **********************************************/
template <class T>
void sortInsertion(T array[], int num)
{
    if (num <= 0)
        return;

    Node<T>* pHead = new Node<T>(array[0]);
    for (int i = 1; i < num; i++)
    {
        // See if we need to insert in the front
        if (pHead->data > array[i])
        {
            Node<T>* temp = new Node<T>(array[i]);
            temp->pNext = pHead;
            pHead = temp;
        }

        // Else traverse and locate where we need to insert
        else
        {
            for (Node<T>* ptr = pHead; ptr; ptr = ptr->pNext)
            {
                Node<T>* temp = new Node<T>(array[i]);
                if (ptr->pNext && ptr->pNext->data > array[i])
                {
                    temp->pNext = ptr->pNext;
                    ptr->pNext = temp;
                    break;
                }
                else if (!ptr->pNext)
                {
                    ptr->pNext = temp;
                    break;
                }
            }
        }
    }

    int i = 0;
    for (Node<T>* ptr = pHead; ptr; ptr = ptr->pNext)
        array[i++] = ptr->data;
}

#endif // INSERTION_SORT_H

