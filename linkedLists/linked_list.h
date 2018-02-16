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

/* Function PushBackElement_For that add element to a linked list using
   the for loop
*/
void PushBackElement_For(struct ListElement list, struct Element *newElem);

/* Function PushBackElement_DoWhile that add element to a linked list using
   the do_while loop
*/
void PushBackElement_DoWhile(struct ListElement list, struct Element *newElem);

/* Function PushBackData that add element to a linked list by a given value
*/
void PushBackData(struct ListElement *list, int value);

/* Function RemoveOneElementByValue that remove an element to a linked list by
   a given value.
   This function goes throuhg the whole linked list and compare each data to
   the value until value == data, the memory allocated is then freed for the
   element N
*/
void RemoveOneElementByValue(struct ListElement list, int value);

/*Function that displays each element of a linked list*/
void DisplayElementOfALinkedList(struct ListElement list);

/* Function RemoveOccurenceByData that remove an element to a linked list by
   a given value.
   This function goes throuhg the whole linked list and compare each data to
   the value until value == data, the memory allocated is then freed for the
   element N and its occurence
*/
void RemoveOccurenceByData(struct ListElement list, int value);
