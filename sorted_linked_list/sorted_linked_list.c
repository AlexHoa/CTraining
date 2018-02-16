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

/*sorting a linked list by selection by moving element*/
void sortListBySelection (struct ListElement *listToSort)
{
    struct Element *elem1; // element that go trough the first loop
    struct Element *elemPrev1; // previous element to element 1
    struct Element *elem2; // element that go through the nested loop
    struct Element *elemPrev2; // previous element to element 2
    struct Element *elemMin; // elem with min data
    struct Element *elemPrevMin; // previous element to element 2

    for (elem1 = listToSort->head; elem1 != NULL; elemPrev1 = elemMin,
                                                  elem1 = elemMin->next)
    {
        elemMin = elem1;
        elemPrev2 = elem1;
        for (elem2 = elem1->next; elem2 != NULL; elemPrev2 = elem2,
                                                 elem2 = elem2->next)
        {
            // find the minimum value
            if (elem2->data < elemMin->data)
            {
                elemMin = elem2;
                elemPrevMin = elemPrev2;
            }
        }
        if (elemMin != elem1)
        {
            // rebuilt the node of the elemMin which has been moved
            elemPrevMin->next = elemMin->next;

            // Insert the element before element 1
            if(elem1 == listToSort->head)
            {
                // 1st case: elem1 = head->list
                listToSort->head = elemMin;
            }
            else
            {
                // if somwhere else in the list
                elemPrev1->next = elemMin;
            }
            elemMin->next = elem1;
        }
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

/*sorting a linked list by selection by changing data*/
void sortListBySelectionDataChange (struct ListElement *listToSort)
{
    // Declaration of an element to go through the list
    struct Element *elem1;
    struct Element *elem2;
    int IntValue;

    //Check that the list is not empty
    if (listToSort->head == NULL)
    {
        printf("The list is empty\n");
        return;
    }

    // Go throught the list to sort
    for (elem1 = listToSort->head; elem1!=NULL; elem1 = elem1->next)
    {
        IntValue = elem1->data;
        for (elem2 = elem1->next; elem2!=NULL; elem2 = elem2->next)
        {
            // find the minimum value
            if (elem2->data < elem1->data)
            {
                IntValue = elem2->data;
                elem2->data = elem1->data;
                elem1->data = IntValue;
            }
        }
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
