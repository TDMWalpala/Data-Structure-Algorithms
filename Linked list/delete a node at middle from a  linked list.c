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

void Delete()
{
    struct node *temp;
    int location;
    printf("Enter location to delete a node :");
    scanf("%d", &location);

    if(location>length())
    {
        printf("Invalid location\n");
    }
    else if(location==1)
    {
        temp = head;
        head = temp->link;
        temp->link = NULL;
        free(temp);
        printf("Node is deleted\n");
    }
    else
    {
        struct node *p = head, *q;
        int i=1;
        while(i<location-1)
        {
            p=p->link;
            i++;
        }
        q = p->link;
        p->link  = q->link;
        q->link=NULL;
        free(q);
        printf("Node is deleted\n");
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


int main()
{
    int choice;
    while(1)
    {
         printf("Linked list operations\n\n");
         printf("1.Insert data\n");
         printf("2.Display\n");
         printf("3.Delete a node at the middle of list\n");
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
           Delete();break;

          case 4:
            exit(1);break;
         }

    }
    return 0;
}
