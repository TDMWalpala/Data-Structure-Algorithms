#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};

struct node *head = NULL;
void insert()
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the node :");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if(head==NULL)
    {
        head = temp;
    }
    else
    {
         struct node* p;
         p=head;
         while(p->link!=NULL)
         {
             p = p->link;
         }
         p->link = temp;
    }

}

int length()
{
    struct node *temp;
    int count=0;
    temp = head;
    while(temp!=NULL)
    {
        count++;
        temp = temp->link;
    }
    return count;
}

void addatafter()
{
    struct node *temp, *p;
    int location, len,i=1;

    printf("Enter the location :");
    scanf("%d", &location);

    len = length();
    if(location>len)
    {
        printf("Invalid location\n");
        printf("Currently list is haven't %d\n",len);
    }
    else
    {
        p = head;
        while(i<location)
        {
            p = p->link;
            i++;
        }
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter node : ");
        scanf("%d", &temp->data);
        temp->link=NULL;
        temp->link = p->link;//right side conection
        p->link = temp; //last side conection
    }
}

void display()
{
    struct node *temp;
    temp = head;
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d-->",temp->data);
            temp = temp->link;
        }
        printf("NULL\n\n");
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
         printf("3.insert a node at the middle of list\n");
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
           addatafter();break;

          case 4:
            exit(1);break;
         }

    }

    return 0;
}
