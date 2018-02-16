/*Define the struct of the doubly linked list*/
struct DoublyElement
{
    int data;
    struct DoublyElement *next;
    struct DoublyElement *prev;
};

/*Declaration of the structure of control*/
struct DoublyListElement
{
    struct DoublyElement *head;
    struct DoublyElement *tail;
};

/*Function that add an element by data in a doubly linked list*/
void PushBackDataDL(struct DoublyListElement *dList, int data);

/*Display elements of a doubly linked list*/
void DisplayElementOfADoublyLinkedList(struct DoublyListElement dList);

