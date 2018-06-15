#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
int info;
struct node *link;
};
struct node *head;

int create_list(int data);
int length();
void display();
void deletepos(int DelPos);
void deleteval(int DelValue);
void update(int UpPos, int UpValue);
void insert(int InPos, int InValue);
bool search(int SearchValue);

int main()
{
    int data, i, n, choice;
    int DelValue, DelChoice, DelPos;
    int UpPos, UpValue;
    int InValue, InPos;
    int SearchValue;
    printf("Enter the number of nodes in this Singly linked list:\n");
    scanf("%d", &n);
    printf("Enter the datum for each node.\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &data);
        create_list(data);
    }
    printf("The data has now been entered.\nThe list is as follows.\n");
    display();
    printf("\nThe length of your Linked List is : %d\n", length());
    printf("Now comes the menu time!!!!!\n");
    while(1){
    printf("Select by pressing the mentioned serial number\n1)Deletion\n2)Searching\n3)Updation\n4)Insertion\n5)Exit\n");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1: printf("\nPress 1 to delete a specific entry\nPress 2 to delete from a position\n");
                scanf("%d", &DelChoice);
                if(DelChoice == 1)
                {
                    printf("Enter the value to be deleted:\n");
                    scanf("%d", &DelValue);
                    if(search(DelValue) == true)
                    {
                         deleteval(DelValue);
                         display();
                    }
                    else if(search(DelValue) == false)
                    {
                        printf("\nSuch value does not exist in the list.\n ");
                    }
                }
                else if (DelChoice == 2)
                {
                    printf("Enter the position: \n");
                    scanf("%d", &DelPos);
                    if(search(DelPos) == true)
                    {
                         deletepos(DelPos);
                         display();
                    }
                    else if(search(DelPos) == false)
                    {
                        printf("\nSuch position does not exist in the list.\n ");
                    }

                }
                else
                    printf("\nWrong choice!!\\n");
                break;

        case 2: printf("\nEnter the value you want to search\n");
                scanf("%d", &SearchValue);
                if(search(SearchValue) == true)
                {
                    printf("The entered value exists in the Linked List.\n");
                }
                else if(search(SearchValue) == false)
                {
                    printf("The entered value does not exist.\n");
                }
                break;

        case 3: printf("\nEnter the position where you want to update:\n");
                scanf("%d", &UpPos);
                printf("\nEnter the new value:\n");
                scanf("%d", &UpValue);
                update(UpPos, UpValue);
                display();
                break;

        case 4: printf("\nEnter the position of insertion:\n");
                scanf("%d", &InPos);
                printf("\nEnter the value of this new node:\n");
                scanf("%d", &InValue);
                if(InPos > 0 && InPos <= length())
                {
                  insert(InPos, InValue);
                  display();
                }
                else
                    printf("\nCannot insert at specified position.\n");
                break;

        case 5: exit(0);

        default : printf("\nInvalid Choice\n");

    }
    }
}

int create_list(int data)
{
    struct node *q, *temp;
    temp = malloc(sizeof(struct node));
    temp -> info = data;
    temp -> link = NULL;
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        q = head;
        while(q -> link != NULL)
        {
            q = q -> link;
        }
        q -> link = temp;
    }
}

void display()
{
    struct node *q;
    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    q = head;
    while(q != NULL)
    {
        printf("%d\t", q ->info);
        q = q -> link;
    }
}

int length()
{
    struct node *qLen;
    int flag = 0;
    qLen = head;
    while(qLen != NULL)
    {
        ++flag;
        qLen = qLen -> link;
    }
    return flag;
}

bool search(int SearchValue)
{
    int i, flag = 0;
    struct node *q;
    q = malloc(sizeof(struct node));
    q = head;
    for(i = 0; i < length(); i++)
    {
        if(q -> info == SearchValue)
        {
            flag = 1;
        }
        else
        {
            q = q -> link;
        }
    }
    return(flag == 1 ? true : false);
}

void deletepos(int DelPos)
{
    int i;
    struct node *q, *p;
    q = malloc(sizeof(struct node));
    p = malloc(sizeof(struct node));
    q = head;
    p = q -> link;
    if(DelPos == 1)
        head = head -> link;
    else if(DelPos > 1 && DelPos < length())
    {
      for(i = 2; i < DelPos; i++)
      {
          p = p -> link;
          q = q -> link;
      }
      q -> link = p -> link;
      q -> link -> info = p -> link -> info;
    }
    else if(DelPos == length())
    {
         while(p -> link != NULL)
        {
             p = p -> link;
             q = q -> link;
        }
        q -> link = NULL;
        free(p);

    }
    else
        printf("Such Position does not exist");
}

void deleteval(int DelValue)
{
    int DelFlag = 0;
    struct node *p, *q;
    p = malloc(sizeof(struct node));
    q = malloc(sizeof(struct node));
    q = head;
    p = q -> link;
    if(DelValue == q -> info)
    {
        head = head -> link;
    }
    else
    {
        while(p -> info != DelValue)
        {
            p = p -> link;
            q = q -> link;
            ++DelFlag;
        }
              if(DelFlag < length() - 2 )
                  {
                       q -> link = p -> link;
                       q -> link -> info = p -> link -> info;
                  }
              else
              {
                   p = NULL;
                   q -> link = NULL;
                   free(p);
              }
    }
}

void update(int UpPos, int UpValue)
{
    int i;
    struct node *q;
    q = malloc(sizeof(struct node));
    q = head;
    for(i = 1; i < UpPos; i++)
    {
       q = q -> link;
    }
    q -> info = UpValue;
}

void insert(int InPos,int InValue)
{
    int i;
    struct node *q, *p;
    q = malloc(sizeof(struct node));
    p = malloc(sizeof(struct node));
    if(InPos == 1)
    {
        q -> info = InValue;
        q -> link = head;
        head = q;
    }
    else if(InPos >= length()+1)
    {
        for(i = 1; i <= length(); i++)
        {
            q = q -> link;
        }
        q -> link = p;
        p -> link = NULL;
        p -> info = InValue;
    }
    else
    {
        q = head;
        for(i = 1; i < InPos; i++)
        {
            q = q -> link;
        }
        p -> link = q -> link;
        p -> info = InValue;
        q -> link = p;

    }
}
