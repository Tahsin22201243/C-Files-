#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *bfr;
    struct node *next;
};

struct node *head = NULL;
                                      //Insert
void beginsert()
{
    struct node *ptr;
    int item;
    ptr = (struct node *) malloc(sizeof(struct node));

    printf("\nEnter value: ");
    scanf("%d", &item);
    ptr->data = item;
    ptr->next = head;
    ptr->bfr = NULL;
    if (head != NULL)
        head->bfr = ptr;
    head = ptr;
    printf("\nNode inserted");
}

void endinsert()
{
    struct node *New, *ptr = head;
    int item;
    New = (struct node *) malloc(sizeof(struct node));

    printf("\nEnter value: ");
    scanf("%d", &item);
    New->data = item;
    New->next = NULL;
    if (head == NULL)
    {
        New->bfr = NULL;
        head = New;
    }
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = New;
    New->bfr = ptr;

    printf("\nNode inserted");
}

void InsertFromPosition()
{
    struct node *New, *ptr = head;
    int item, pos;

    New = (struct node *) malloc(sizeof(struct node));

    printf("\nEnter value: ");
    scanf("%d", &item);
    New->data = item;
    New->next = NULL;
    printf("\nEnter index: ");
    scanf("%d", &pos);

    for (int i = 1; i < pos - 1; i++)
    {
        ptr = ptr->next;
    }
    New->next = ptr->next;
    ptr->next = New;
    New->bfr = ptr;
    New->next->bfr = New;

    printf("\nNode inserted");
}
                                         //Delete
void deleteFromBeginning()
{
    struct node *ptr = head;
    head = ptr->next;
    free(ptr);
    head-> bfr = NULL;
    printf("\nNode deleted");
}

void deleteFromEnd()
{
    struct node *ptr = head, *New = NULL;
    while(ptr->next !=NULL)
    {
        New = ptr;
        ptr = ptr->next;
    }
    New->next = NULL;
    free(ptr);
    printf("\nNode deleted");

}

void deleteFromPosition()
{
    struct node *New, *ptr = head;
    int pos;

    printf("\nEnter index: ");
    scanf("%d", &pos);

    for (int i = 1; i < pos - 1; i++) {
        ptr = ptr->next;
    }

        New = ptr -> next;
        ptr -> next = New -> next;
        New -> next -> bfr = ptr;
        free(New);

    printf("\nNode deleted");
}

                                //7. Search a node by value
void searchValue()
{
    struct node *ptr = head;

    int value, position = 1;
    printf("\nEnter the value: ");
    scanf("%d", &value);
    while (ptr != NULL)
    {
        if (ptr->data == value)
        {
            printf("\nvalue %d And position %d.", value, position);
            return;
        }
        ptr = ptr->next;
        position++;
    }
    printf("\nvalue %d not found.", value);
}
                          //8.Search a node by position

void searchPosition()
{
    struct node *ptr = head;

    int position, currentPos = 1;
    printf("\nEnter the position: ");
    scanf("%d", &position);
    while (ptr != NULL)
    {
        if (currentPos == position)
        {
            printf("\nposition %d And value %d.", position, ptr->data);
            return;
        }
        ptr = ptr->next;
        currentPos++;
    }
    printf("\nNode at position %d not found.", position);
}
                                 //9.Reverse Order
void ReversePrint()
{
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    printf("\nPrinting in reverse order: ");
    while (ptr != NULL)
    {
        printf("%d-> ", ptr->data);
        ptr = ptr->bfr;
    }
}
                              //10. Doubly to Array Convert
int *ArrayConvert()
{
    int count = 0;
    struct node *ptr = head;

    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }

    int *arr = (int *)malloc((count + 1) * sizeof(int));


    ptr = head;
    int i = 0;
    while (ptr != NULL)
    {
        arr[i++] = ptr->data;
        ptr = ptr->next;
    }
    arr[count] = -1;
    printf("\n Converted to array successfully.");
    return arr;
}


                                        //11.Convert to Circular
void DoublytoCircular()
{
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = head;
    head->bfr = ptr;
}
                                   //Cancle Circular Linked List
void CircularCancle()
{
    struct node *ptr = head;

    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = NULL;
    head->bfr = NULL;
}



void CircularPrint()
{

    struct node *ptr = head;
    printf("\nCircular Doubly Linked List: ");
    do
    {
        printf("%d-> ", ptr->data);
        ptr = ptr->next;
    }
    while (ptr != head);
}

void DoublyPrint()
{
    struct node *ptr = head;
    printf("\nPrinting values . . . . .\n");
    while (ptr != NULL)
    {
        printf("%d-> ", ptr->data);
        ptr = ptr->next;
    }
}


int main ()
{
    int choice = -1;
    while (choice != 0)
    {
        printf("\nMain Menu\n");
        printf("*********************");
        printf("\n1. Insert in beginning");
        printf("\n2. Insert in Ending");
        printf("\n3. Insert in any specific position");
        printf("\n4. Delete from beginning");
        printf("\n5. Delete from end");
        printf("\n6. Delete from any specific position");
        printf("\n7. Search a node by value");
        printf("\n8. Search a node by position");
        printf("\n9. Print in reverse order");
        printf("\n10. Convert the doubly linked list to circular doubly linked list");
        printf("\n11. Convert the circular doubly linked list to doubly linked list");
        printf("\n12. Print Circular doubly linked list");
        printf("\n13. Print doubly linked list");
        printf("\n14. Linked list converted to array");
        printf("\n0. Exit\n");
        printf("************************************");
        printf("\nEnter your choice? ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            beginsert();
            break;
        case 2:
            endinsert();
            break;
        case 3:
            InsertFromPosition();
            break;
        case 4:
            deleteFromBeginning();
            break;
        case 5:
            deleteFromEnd();
            break;
        case 6:
            deleteFromPosition();
            break;
        case 7:
            searchValue();
            break;
        case 8:
            searchPosition();
            break;
        case 9:
            ReversePrint();
            break;
        case 10:
            DoublytoCircular();
            break;
        case 11:
            CircularCancle();
            break;
        case 12:
            CircularPrint();
            break;
        case 13:
            DoublyPrint();
            break;
        case 14:
            ArrayConvert();
            break;
        case 0:
            exit(0);
        default:
            printf("Enter valid Info");
        }
    }
    return 0;
}
