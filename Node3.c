
#include<stdio.h>
#include<stdlib.h>

    struct node{
    int info;
    struct node *link;
    };
    struct node *head;

void create_list(int data);
void display();
void deleteFirstNode();
void deleteLastNode();
void deleteMiddleNode(int position);
int main()
{
    int i, data, n, choice, position;
    head = NULL;
    printf("Enter the number of Nodes\n");
    scanf("%d", &n);
    printf("Enter data to each node:\n");


    for(i = 0; i < n; i++)
    {

        scanf("%d", &data);
        create_list(data);
    }
    display();
     printf("\n1 for deletion at start\n2for deletion at end\n3 for deletion from mid\n");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
    deleteFirstNode();
    printf("List after deletion\n");
    display();
    break;
    case 2:
    deleteLastNode();
    printf("List after deletion\n");
    display();
    break;
    case 3:
        printf("Enter position\n");
        scanf("%d", &position);
        deleteMiddleNode(position);
        printf("List after deletion\n");
    display();
    break;
    default :
        printf("Invalid\n");
    }
}

void create_list(int data)
{
    struct node *temp, *q;
    temp = malloc(sizeof(struct node));
    temp -> info = data;
    temp -> link = NULL;
    if(head == NULL)
        head = temp;
    else
    {
        q = head;
        while(q -> link != NULL)
            q = q -> link;
        q -> link = temp;
    }
}
void display()
{
    struct node *q;
    if(head == NULL)
    {
        printf("List is empty\n");
    }
    q = head;
    while(q != NULL)
    {
        printf("%d\t", q -> info);
        q =q -> link;
    }
}

    void deleteFirstNode()
{
    struct node *Delete;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        Delete = head;
        head = head->link;

        printf("\nData deleted = %d\n", Delete->info);


        free(Delete);


    }
}

  void deleteLastNode()
{
    struct node *toDelete, *secondLastNode;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        secondLastNode = head;


        while(toDelete->link != NULL)
        {
            secondLastNode = toDelete;
            toDelete = toDelete->link;
        }

        if(toDelete == head)
        {
            head = NULL;
        }
        else
        {

            secondLastNode->link = NULL;
        }


        free(toDelete);


    }
}

void deleteMiddleNode(int position)
{
    int i;
    struct node *toDelete, *prevNode;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        prevNode = head;

        for(i=2; i<=position; i++)
        {
            prevNode = toDelete;
            toDelete = toDelete->link;

            if(toDelete == NULL)
                break;
        }

        if(toDelete != NULL)
        {
            if(toDelete == head)
                head = head->link;

            prevNode->link = toDelete->link;
            toDelete->link = NULL;


            free(toDelete);

        }
        else
        {
            printf("Invalid position unable to delete.");
        }
    }
}


