/*sorting a linke list by insertion*/
// Declaration of the structure Element
struct Element
{
    int data;
    struct Element *next;
};

// Declaration of the structure of control
struct ListElement
{
    struct Element *head;
};


/* Function insertElementSortedLinkedList that add element to a sorted linked
list in a sorting way
*/
void insertElementSortedLinkedList(struct ListElement *list,
                                   struct Element *newElem);

/*Function that displays each element of a linked list*/
void DisplayElementOfALinkedList(struct ListElement list);

/* Function insertDataSortedLinkedList that add data to a sorted linked
list in a sorting way
*/
void insertDataSortedLinkedList(struct ListElement *list, int data);

/*function that sorts a linked list by insertion*/
void sortListByInsertion (struct ListElement *listToSort,
                          struct ListElement *sortedList);

/*sorting a linked list by selection by moving element*/
void sortListBySelection (struct ListElement *listToSort);

/*sorting a linked list by selection by changing data*/
void sortListBySelectionDataChange (struct ListElement *listToSort);

/* Function PushBackElement_For that add element to a linked list using
   the for loop
*/
void PushBackElement_For(struct ListElement *list, struct Element *newElem);
