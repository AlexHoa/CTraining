#include <stdio.h>
#include <stdlib.h>
#include "sorted_linked_list.h"

/*sorting a linked list by insertion*/

/* Function insertElementSortedLinkedList that add element to a sorted linked
list in a sorting way
*/
void insertElementSortedLinkedList(struct ListElement *list,
                                   struct Element *newElem)
{
    // creation of an element
    struct Element *elem;
    struct Element *elemPrev = list->head;

    //Check if the list is not empty
    if (list->head == NULL)
    {
        // insert the element if the list is empty
        list->head = newElem;
    }
    else
    {
        // go through the list
        for (elem = list->head; elem != NULL; elemPrev = elem, elem = elem->next)
        {
            // compare the element to insert to the other elements
            if ((newElem->data < elem->data) && (elem == list->head))
            {
                /*The element to insert is inferior to all elements: this is the
                begin of the list */
                list->head = newElem;
                newElem->next = elem;
            }
            else if ((newElem->data > elem->data) && (elem->next == NULL))
            {
                /*The element to insert is superior to all elements in the list
                */
                elem->next = newElem;
                newElem->next = NULL;
            }
            else if ((newElem->data < elem->data) &&
                     (newElem->data > elemPrev->data))
            {
                /*The element to insert is between to element*/
                elemPrev->next = newElem;
                newElem->next = elem;
            }
        }
    }
}

/* Function insertDataSortedLinkedList that add data to a sorted linked
list in a sorting way
*/
void insertDataSortedLinkedList(struct ListElement *list, int data)
{
    // creation of an element
    struct Element *elem;
    struct Element *elemPrev = list->head;
    struct Element *newElem = malloc(sizeof(struct Element));

    // Check memory allocation
    if (newElem == NULL)
    {
        return;
    }

    newElem->data = data;

    //Check if the list is not empty
    if (list->head == NULL)
    {
        // insert the element if the list is empty
        list->head = newElem;
        newElem->next = NULL;
    }
    else
    {
        // go through the list
        for (elem = list->head; elem != NULL; elemPrev = elem, elem = elem->next)
        {
            // compare the element to insert to the other elements
            if ((newElem->data < elem->data) && (elem == list->head))
            {
                /*The element to insert is inferior to all elements: this is the
                begin of the list */
                list->head = newElem;
                newElem->next = elem;
            }
            else if ((newElem->data > elem->data) && (elem->next == NULL))
            {
                /*The element to insert is superior to all elements in the list
                */
                elem->next = newElem;
                newElem->next = NULL;
            }
            else if ((newElem->data < elem->data) &&
                     (newElem->data > elemPrev->data))
            {
                /*The element to insert is between to element*/
                elemPrev->next = newElem;
                newElem->next = elem;
            }
        }
    }
}

/*function that sorts a linked list by insertion*/
void sortListByInsertion (struct ListElement *listToSort,
                          struct ListElement *sortedList)
{

    // Declaration of an element to go through the list
    struct Element *elemToInsert;

    // Go throught the list to sort
    for (elemToInsert = listToSort->head; elemToInsert!=NULL;
         elemToInsert = elemToInsert->next)
    {
        // Insert each Element in the sorted list in a sorted way
        insertDataSortedLinkedList(sortedList, elemToInsert->data);
    }
}

/*Function that displays each element of a linked list*/
void DisplayElementOfALinkedList(struct ListElement list)
{
    struct Element *elem;
    int i = 0;

    // Check if the list is non empty
    if (list.head != NULL)
    {
        for (elem = list.head; elem != NULL; elem = elem->next)
        {
            printf("Element %d: elem->data %d, elem ->next %p\n", i++,
            elem->data, elem->next);
        }
    }
    else
    {
        printf("The linked list is empty\n");
    }
}

/* Function PushBackElement_For that add element to a linked list using
   the for loop
*/
void PushBackElement_For(struct ListElement *list, struct Element *newElem)
{
    // 2. the pointer to head is not NULL -> find the pointer NULL
    //and add the element
    struct Element *elem;

    if (list->head != NULL)
    {
        for (elem = list->head; elem != NULL;)
        {
            if (elem->next != NULL)
            {
                elem = elem->next;
            }
            else
            {
                elem->next = newElem;
                break;
            }
        }
    }
    else
    {
        list->head = newElem;
    }
}
