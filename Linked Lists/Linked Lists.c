#include <stdio.h>
#include <stdlib.h>

void addHead(int x);                // add value at the beginning of the linked lists
void addTail(int x);                // add value at the ending of the linked lists
void addLoc(int x, int loc);        // add value at specific location of the linked lists
void delHead();                     // delete value from the beginning of the linked lists
void delTail();                     // delete value from the ending of the linked lists
void delValue(int x);               // delete specific value of the linked lists
void delLoc(int loc);               // delete value at specific location of the linked lists
void reverseList();                 // reverse print the linked lists
void printList();                   // print the linked lists
int length();                       // return length of the linked lists

struct node {
    int value;
    struct node *next;
}*head;                             // declare a pointer which contains the address of the first node

int main()
{
    int a;                          // a variable for switch control

    while(1)                        // infinite loop
    {
        printf("\n::Main Menu::\n\n");
        printf("Choose the number\n\n");
        printf("1. Add node at the beginning\n");
        printf("2. Add node at the last\n");
        printf("3. Add node at the particular location\n");
        printf("4. Delete the beginning node\n");
        printf("5. Delete the last node\n");
        printf("6. Delete the particular node ( value wise )\n");
        printf("7. Delete the particular node ( location wise )\n");
        printf("8. Print the values in reverse way\n");
        printf("9. Print the elements in the list\n");
        printf("10. Print number of elements in the list\n");
        printf("11. Exit\n");
        printf("\n\nChoose Option\n");
        scanf("%d",&a);

        switch(a)
        {
            case 1:
            {
                int num;
                printf("\nEnter Value : ");
                scanf("%d",&num);
                printf("\n");

                addHead(num);
                printList();

                break;
            }

            case 2:
            {
                int num;
                printf("\nEnter Value : ");
                scanf("%d",&num);

                addTail(num);
                printList();

                break;
            }

            case 3:
            {
                int num,loc;

                printf("\nEnter Value : ");
                scanf("%d",&num);
                printf("\nEnter Location : ");
                scanf("%d",&loc);

                addLoc(num,loc);
                printList();

                break;
            }

            case 4:
            {
                delHead();
                printList();

                break;
            }

            case 5:
            {
                delTail();
                printList();

                break;
            }

            case 6:
            {
                int val;
                printf("\n Enter Value for delete : ");
                scanf("%d",&val);

                delValue(val);
                printList();

                break;
            }

            case 7:
            {
                int loc;
                printf("\nEnter location for delete : ");
                scanf("%d",&loc);

                delLoc(loc);
                printList();

                break;
            }

            case 8:
            {
                printf("The reverse value is : ");

                reverseList();
                printList();

                break;
            }

            case 9:
                {
                    printList();

                    break;
                }

            case 10:
                {
                    printList();
                    printf("\nTotal number of nodes in the list : %d\n",length());
                }

            case 11:
                {
                    struct node *temp;

                    while(head != NULL)             // using this for deleting full list before exit
                    {
                        temp = head->next;
                        free(head);
                        head = temp;
                    }

                    exit(0);
                }

            default:
                {
                    printf("\nWrong Option Chosen\n");
                }
        }
    }
}

// add value at the beginning of the linked lists
void addHead(int x)
{
    struct node *newItem;

    newItem = (struct node*)malloc(sizeof(struct node));

    newItem->value = x;
    newItem->next = NULL;

    if(head == NULL)
    {
        head = newItem;
        head->next = NULL;
    }
    else
    {
        newItem->next = head;
        head->next = NULL;
    }
}


// add value at the ending of the linked lists
void addTail(int x)
{
    struct node *newItem;

    newItem = (struct node*)malloc(sizeof(struct node));

    newItem->value = x;
    newItem->next = NULL;

    struct node *prev;

    prev = head;

    if(head == NULL)
    {
        head = newItem;
        head->next = NULL;
    }
    else
    {
        while(prev->next != NULL)
        {
            prev = prev->next;
        }

        prev->next = newItem;
    }
}

// add value at specific location of the linked lists
void addLoc(int x, int loc)
{
    struct node *newItem;
    int i;

    newItem = (struct node*)malloc(sizeof(struct node));

    newItem->value = x;
    newItem->next = NULL;

    struct node *cur,*prev;

    cur = head;

    if(loc > length()+1 || loc <=0)
    {
        printf("\nInsertion node is not possible in this location\n");
    }
    else
    {
        if(loc == 1)
        {
            addHead(x);
        }
        else
        {
            for(i=1;i<loc;i++)
            {
                prev = cur;
                cur = cur->next;
            }
            prev->next = newItem;
            newItem->next = cur;
        }
    }
}

// delete value from the beginning of the linked lists
void delHead()
{
    struct node *cur;

    if(head == NULL)
    {
        return;
    }
    else
    {
        cur = head;
        head = head->next;

        free(cur);
    }
}

// delete value from the ending of the linked lists
void delTail()
{
    struct node *cur,*prev;

    cur = head;
    prev = NULL;

    while(cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    if(prev != NULL)
    {
        prev->next = cur->next;
    }
    free(cur);
}

// delete specific value of the linked lists
void delValue(int x)
{
    struct node *cur,*prev;

    cur = head;
    prev = NULL;

    if(head == NULL)
    {
        return;
    }
    else
    {
        while(cur->value != x)
        {
            prev = cur;
            cur = cur->next;
        }

        if(cur->value != head->value && cur->next != NULL)
        {
            prev->next = cur->next;
            free(cur);
        }
        else
        {
            delHead();
        }
    }
}

// delete value at specific location of the linked lists
void delLoc(int loc)
{
    struct node *cur,*prev;
    int i;

    cur = head;
    prev = NULL;

    if(loc > length()+1 || loc <=0)
    {
        printf("\nDeletion is not possible in this location\n");
    }
    else
    {
        if(loc == 1)
        {
            head = cur->next;
            free(cur);
            return;
        }
        else
        {
            for(i=1;i<loc;i++)
            {
                prev = cur;
                cur= cur->next;
            }
            prev->next = cur->next;
            free(cur);
        }
    }
}

// reverse print the linked lists
void reverseList()
{
    struct node *cur,*prev,*temp;

    cur = head;
    prev = NULL;

    while(cur != NULL)
    {
        temp = prev;
        prev = cur;
        cur = cur->next;
        prev->next = temp;
    }
    head = prev;
}

// print the linked lists
void printList()
{
    struct node *cur;
    int count = 1;

    cur = head;

    if(head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        printf("Elements are : \n");

        while(cur != NULL)
        {
            printf("%d at location %d\n",cur->value,count);
            cur = cur->next;
            count++;
        }
        printf("\n");
    }
}

// return length of the linked lists
int length()
{
    struct node *cur;
    int count = 0;

    cur = head;

    while(cur != NULL)
    {
        cur = cur->next;
        count++;
    }
    return count;
}
