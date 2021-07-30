#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *head=NULL;

void creatlist()
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the node : ");
    scanf("%d",&temp->data);
    temp->link=NULL;
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
           p=p->link;
        }
        p->link = temp;
    }

}

void display()
{
    struct node *temp;
    temp = head;
    if(temp==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->link;
        }
        printf("NULL\n\n");
    }
}

void reverselist()
{
    int i,j,k,len;
    len = length();
    struct node *p,*q,*temp;
    i=0;
    j=len-1;
    p=q=head;

    while(i<j)
    {
        k=0;
        while(k<j)
        {
            q = q->link;
            k++;
        }
        temp = q->data;
        q->data = p->data;
        p->data = temp;
        i++;
        j--;
        p=p->link;
        q=head;
    }
    display();

}

int length()
{
    int count=0;
    struct node *temp;
    temp = head;
    while(temp!=NULL)
    {
        count++;
        temp = temp->link;
    }
  //printf("count %d", count);
  return count;
}


int main()
{
    int choice;
    while(1)
    {
         printf("Linked list operations\n\n");
         printf("1.Insert data\n");
         printf("2.Display\n");
         printf("3.Reverse list\n");
         printf("4.Exit"\n);
         printf("Enter your choice : \n");
         scanf("%d", &choice);

         switch(choice)
         {
          case 1:
           creatlist();break;

          case 2:
           display();break;

          case 3:
            reverselist();break;

          case 4:
            exit(1);break;
         }

    }

    return 0;
}
