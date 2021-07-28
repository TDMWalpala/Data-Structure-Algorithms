/*Single linked list operation*/
#include <stdio.h>
#include <stdlib.h>
int len;
struct node
{
    int data;
    struct node* link;
};

struct node* head = NULL;

void append(void)
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter node data : ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if(head == NULL)//list is empty
    {
        head = temp;
    }
    else
    {
        struct node* p;
        p = head;
        while(p->link!=NULL)
        {
            p = p->link;
        }
        p->link = temp;

    }
}

int length(void)
{
   int count=0;
   struct node* temp;
   temp = head;
   while(temp!= NULL)
   {
       count++;
       temp = temp->link;
   }
   return count;
}

void display(void)
{
    struct node* temp;
    temp = head;
    if(temp == NULL)
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
        printf("\n\n");
    }
}

void main(void)
{
    int choice;
    while(1)
    {
      printf("Single Linked List Operations : \n");
      printf("1.Append\n");
      printf("2.Insert_at_begining\n");
      printf("3.Insert_at_last\n");
      printf("4.Length\n");
      printf("5.Display\n");
      printf("6.Delete\n");
      printf("7.Quit\n");

      printf("Enter your choice : ");
      scanf("%d", &choice);
      switch(choice)
      {
      case 1:
        {
          append();break;
        }
      case 2:
        {
            //insert_being();
            break;
        }
      case 3:
        {
            //insert_last()
            ;break;
        }
      case 4:
        {
            len = length();
            printf("Length : %d\n", len);
            break;
        }
      case 5:
        {
            display();break;
        }
      case 6:
        {
            //Delete();
            break;
        }
      case 7:
        {
            exit(1);
            break;
        }
      default :
        {
            printf("Invalid choice!\n");
        }
      }
    }
    return 0;
}
