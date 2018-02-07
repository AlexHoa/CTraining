#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/* Function PushBackElement_For that add element to a linked list using
   the for loop
*/
void PushBackElement_For(struct ListElement list, struct Element *newElem)
{
    // 2. the pointer to head is not NULL -> find the pointer NULL
    //and add the element
    struct Element *elem;

    if (list.head != NULL)
    {
        for (elem = list.head; elem != NULL;)
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
        list.head = newElem;
    }
}

/* Function PushBackElement_DoWhile that add element to a linked list using
   the do_while loop
*/
void PushBackElement_DoWhile(struct ListElement list, struct Element *newElem)
{
    struct Element *elem;

    if (list.head == NULL)
    {
        list.head = newElem;
    }
    else
    {
        elem = list.head;
        do
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
        } while (elem != NULL);
    }
}

/* Function PushBackData that add element to a linked list by a given value
*/
void PushBackData(struct ListElement list, int value)
{
    struct Element *elem;

    struct Element *newElement = malloc(sizeof(struct Element));

    // Chack that a memory area has been allocated
    if (newElement == NULL)
    {
        return;
    }

    newElement->data = value;
    newElement->next = NULL;

    if (list.head != NULL)
    {
        for (elem = list.head; elem != NULL;)
        {
            if (elem->next != NULL)
            {
                elem = elem->next;
            }
            else
            {
                elem->next = newElement;
                break;
            }
        }
    }
    else
    {
        list.head = newElement;
    }
}

/* Function RemoveOneElementByValue that remove an element to a linked list by
   a given value.
   This function goes throuhg the whole linked list and compare each data to
   the value until value == data, the memory allocated is then freed for the
   element N
*/
void RemoveOneElementByValue(struct ListElement list, int value)
{
    // go through the linked list
    struct Element *elem; //current element
    struct Element *elemN_1 = list.head; // element N-1

    // Check if the list is non empty
    if (list.head != NULL)
    {
        for (elem = list.head; elem != NULL; elemN_1 = elem, elem = elem->next)
        {
            if (elem->data == value)
            {
                if (elem == list.head)
                {
                    /*
                       if the element to remove is at the begin of the list, the
                       head of the list changes and is linked to the element N+1
                    */

                    list.head = elem->next;
                }
                else if (elem->next == NULL)
                {
                    /*
                       if the element to remove is at the end of the list, the
                       last element is removed and the second to last element
                       becomes the last element and so elemN_1->next = NULL
                    */

                    elemN_1->next = NULL;
                }
                else
                {
                    /*
                       if the element is somewhere else in the list the element
                       N-1 is linked to the element N+1
                    */

                    elemN_1->next = elem->next;
                }
                free(elem);
                break;
            }
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

/**/
