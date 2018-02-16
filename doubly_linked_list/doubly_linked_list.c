#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

/*Function that add an element by data in a doubly linked list*/
void PushBackDataDL(struct DoublyListElement *dList, int data)
{
    // Declare an element to go through the list
    struct DoublyElement *dElem;

    // Declare an element to insert
    struct DoublyElement *newdElem = malloc(sizeof(struct DoublyElement));

    // Check memory allocation
    if (newdElem == NULL)
    {
        printf("Allocation failed\n");
        return;
    }

    //Affect data to the element
    newdElem->data = data;
    newdElem->next = NULL;
    newdElem->prev = NULL;

    if (dList->head == NULL || dList->tail == NULL)
    {
        // Case 1: the list is empty
        dList->head = newdElem;
        dList->tail = newdElem;
    }
    else
    {
        // Case 2: the list is not empty, add the element at the end
        for (dElem = dList->head; dElem != NULL;)
        {
            if (dElem->next != NULL)
            {
                dElem = dElem->next;
            }
            else
            {
                dElem->next = newdElem;
                newdElem->prev = dElem;
                dList->tail = newdElem;
                break;
            }
        }
    }
}

/*Display elements of a doubly linked list*/
void DisplayElementOfADoublyLinkedList(struct DoublyListElement dList)
{
    // element that go through the linked list
    struct DoublyElement *dElem;
    int i = 0;

    for (dElem = dList.head; dElem != NULL; dElem = dElem->next)
    {
        printf("dElem %d: dElem->data = %d, ", i++, dElem->data);
        printf("dElem adress %d, ", dElem);
        printf("dElem->next = %d, dElem->prev = %d\n", dElem->next, dElem->prev);
    }
}

