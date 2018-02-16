/*
- Nouveau dossier pour le projet
- Fichier .h pour les déclarations
- Fichier .c pour l'implémentation
- Choisir des bon noms pour les fichiers et les variables/fonctions
- Ecrire un script compile.sh contenant les commandes de compilation:
  générations des fichiers .o et l'exécutable
- définir des scénarios des tests.
*/

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main()
{
    /*Tests of the linked list functions*/
    // Creation of  list and element to test
    struct Element *ElementTest1 = malloc(sizeof(struct Element));
    struct ListElement myList;
    int test = 10;

    // Check that memory spaces has been allocated for ElementTest1
    if (ElementTest1 == NULL)
    {
        goto end;
        // or return -1;
    }
    //Element Test1
    ElementTest1->data = 8;
    ElementTest1->next = NULL;

    struct Element *ElementTest2 = malloc(sizeof(struct Element));

    // Check that memory spaces has been allocated for ElementTest2
    if (ElementTest2 == NULL)
    {
        free(ElementTest1);
        ElementTest1 = NULL;
        goto end;
        // or return -1;
    }
    //Element Test2
    ElementTest2->data = 56;
    ElementTest2->next = NULL;

    struct Element *ElementTest3 = malloc(sizeof(struct Element));

    // Check that memory spaces has been allocated for ElementTest3
    if (ElementTest3 == NULL)
    {
        free(ElementTest1);
        ElementTest1 = NULL;
        free(ElementTest2);
        ElementTest2 = NULL;
        goto end;
        // or return -1;
    }
    //Element Test3
    ElementTest3->data = 21;
    ElementTest3->next = NULL;

    // Check that memory spaces has been allocated for ElementTest2
    myList.head = ElementTest1;

    // Test of the fucntion DisplayElementOfALinkedList() before insertion
    printf("Before insertion\n");
    DisplayElementOfALinkedList(myList);

    // Test of the function PushBackElement_For()
    PushBackElement_For(myList, ElementTest2);

    // Test of the fucntion PushBackElement_DoWhile()
    PushBackElement_DoWhile(myList, ElementTest3);

    // Test of the fucntion PushBackData()
    PushBackData(&myList, test);

    // Test of the fucntion DisplayElementOfALinkedList() after insertion
    printf("After insertion\n");
    DisplayElementOfALinkedList(myList);

    // Test of the function RemoveOneElementByValue()
    RemoveOneElementByValue(myList, 56);

    // Test of the fucntion DisplayElementOfALinkedList() after removing element
    printf("After Remove one element\n");
    DisplayElementOfALinkedList(myList);

    // Insert Occurence of Data first
    PushBackData(&myList, 1);
    PushBackData(&myList, 3);
    PushBackData(&myList, 2);
    PushBackData(&myList, 1);
    PushBackData(&myList, 4);
    PushBackData(&myList, 1);
    PushBackData(&myList, 1);

    // Display list with occurence
    printf("list with occurence\n");
    DisplayElementOfALinkedList(myList);

    // test of the function RemoveOccurenceByData
    RemoveOccurenceByData(myList, 1);
    printf("list after removing occurence\n");
    DisplayElementOfALinkedList(myList);

end:
    // Free elements
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

    return 0;
}

