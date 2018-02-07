#include <stdio.h>
#include <stdlib.h>
#include "sorted_linked_list.h"

int main()
{
    printf("Begin of test insertElementSortedLinkedList\n");
    /*Test of the function insertElementSortedLinkedList */
    // Declaration of the list
    struct ListElement myList;
    myList.head = NULL;

    DisplayElementOfALinkedList(myList);
    // Declaration of elementTest1 and verify memory allocation
    struct Element *elemTest1 = malloc(sizeof(struct Element));

    printf("add Element1\n");
    if (elemTest1 != NULL)
    {
        elemTest1->data = 8;
        elemTest1->next = NULL;
        insertElementSortedLinkedList(&myList, elemTest1);
    }

    DisplayElementOfALinkedList(myList);
    // Declaration of elementTest2 and verify memory allocation
    struct Element *elemTest2 = malloc(sizeof(struct Element));

    printf("add Element2\n");
    if (elemTest2 != NULL)
    {
        elemTest2->data = 12;
        elemTest2->next = NULL;
        insertElementSortedLinkedList(&myList, elemTest2);
    }

    DisplayElementOfALinkedList(myList);

    // Declaration of elementTest3 and verify memory allocation
    struct Element *elemTest3 = malloc(sizeof(struct Element));

    printf("add Element3\n");
    if (elemTest3 != NULL)
    {
        elemTest3->data = 7;
        elemTest3->next = NULL;
        insertElementSortedLinkedList(&myList, elemTest3);
    }

    DisplayElementOfALinkedList(myList);

    // Declaration of elementTest4 and verify memory allocation
    struct Element *elemTest4 = malloc(sizeof(struct Element));

    printf("add Element4\n");
    if (elemTest4 != NULL)
    {
        elemTest4->data = 9;
        elemTest4->next = NULL;
        insertElementSortedLinkedList(&myList, elemTest4);
    }
    DisplayElementOfALinkedList(myList);
    

    // Free all elements
    if (elemTest1)
    {
        free(elemTest1);
    }

    if (elemTest2)
    {
        free(elemTest2);
    }

    if (elemTest3)
    {
        free(elemTest3);
    }

    if (elemTest4)
    {
        free(elemTest4);
    }

    printf("End of test insertElementSortedLinkedList\n");
    
    printf("begin of test insertDataSortedLinkedList / sortListByInsertion\n");
    /*Tests of the functions insertDataSortedLinkedList and 
    sortListByInsertion*/
    // Declaration of the lists
    struct ListElement mySortedList;
    struct ListElement myListToSort;
    mySortedList.head=NULL;
    // Declaration of several elements of myList and check memory allocation
    struct Element *ElementTest1 = malloc(sizeof(struct Element));

    if (ElementTest1)
    {
        ElementTest1->data = 8;
        ElementTest1->next = NULL;
        PushBackElement_For(&myListToSort, ElementTest1);
    }

    struct Element *ElementTest2 = malloc(sizeof(struct Element));

    if (ElementTest2)
    {
        ElementTest2->data = 45;
        ElementTest2->next = NULL;
        PushBackElement_For(&myListToSort, ElementTest2);
    }

    struct Element *ElementTest3 = malloc(sizeof(struct Element));

    if (ElementTest3)
    {
        ElementTest3->data = 3;
        ElementTest3->next = NULL;
        PushBackElement_For(&myListToSort, ElementTest3);
    }

    struct Element *ElementTest4 = malloc(sizeof(struct Element));

    if (ElementTest4)
    {
        ElementTest4->data = 7;
        ElementTest4->next = NULL;
        PushBackElement_For(&myListToSort, ElementTest4);
    }

    // Display the list before sorting
    printf("list before sorting\n");
    DisplayElementOfALinkedList(myListToSort);

    // Sort the list by insertion
    sortListByInsertion (&myListToSort, &mySortedList);

    // Display the list after insertion
    printf("list after sorting\n");
    DisplayElementOfALinkedList(mySortedList);

    // Free Elements
    if (ElementTest1)
    {
        free(ElementTest1);
    }

    if (ElementTest2)
    {
        free(ElementTest2);
    }

    if (ElementTest3)
    {
        free(ElementTest3);
    }

    if (ElementTest4)
    {
        free(ElementTest4);
    }

    printf("end of test insertDataSortedLinkedList / sortListByInsertion\n");
    return 0;
}

