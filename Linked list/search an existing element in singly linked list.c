#include <stdio.h>
#include <stdlib.h>

struct node{
 int data;
 struct node *link;
};

struct node *head;

void insert()
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the node :");
    scanf("%d", &temp->data);
    temp->link=NULL;

    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node *p;
        p=head;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link = temp;
    }
}

int length()
{
    struct node *temp;
    int count = 0;
    temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->link;
    }
    return count;
}

void display()
{
    struct node *temp;
    temp =head;
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(temp!= NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->link;
        }
        printf("NULL\n\n");
    }
}

void search()
{
    struct node *temp;
    temp = head;
    printf("Enter the location : ");
    int location;
    scanf("%d",&location);
    if(location>length())
    {
        printf("Invalid location\n");
    }
    else
    {
        int i=1;
        while(i<location)
        {
            temp = temp->link;
            i++;
        }
        printf(">>>%d\n",temp->data);
    }
}

int main()
{
    int choice;
    while(1)
    {
         printf("Linked list operations\n\n");
         printf("1.Insert data\n");
         printf("2.Display\n");
         printf("3.Search an node\n");
         printf("4.Exit\n");
         printf("Enter your choice : \n");
         scanf("%d", &choice);

         switch(choice)
         {
          case 1:
           insert();break;

          case 2:
           display();break;

          case 3:
           search();break;

          case 4:
           exit(1);break;
         }

    }
    return 0;
}
