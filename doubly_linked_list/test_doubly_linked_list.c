#include <stdio.h>
#include <stdio.h>
#include "doubly_linked_list.h"

int main()
{
    // Declaration of the list to test
    struct DoublyListElement myDListToTest;
    myDListToTest.tail = NULL;
    myDListToTest.head = NULL;

    // Diplay the list before insertion of data
    printf("List before insertion of data:\n");
    DisplayElementOfADoublyLinkedList (myDListToTest);

    // Test of the function
    PushBackDataDL (&myDListToTest, 2);
    PushBackDataDL (&myDListToTest, 1);
    PushBackDataDL (&myDListToTest, 9);
    PushBackDataDL (&myDListToTest, 10);
    PushBackDataDL (&myDListToTest, 4);

    // Diplay the list before insertion of data
    printf("List after insertion of data:\n");
    DisplayElementOfADoublyLinkedList (myDListToTest);
}

