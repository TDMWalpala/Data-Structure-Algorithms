#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *front=NULL;
struct node *rear=NULL;

void enqueue()
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data :");
    scanf("%d", &temp->data);
    printf("Enqueue : %d\n", temp->data);
    temp->link=NULL;

    if(front==NULL && rear==NULL)
    {
    	front=temp;
    	rear=temp;
    }
    else
    {
    	rear->link=temp;
    	rear=temp;
    }
}

void dequeue()
{
	struct node* temp;
	temp=front;
	if(front==NULL)
	{
		printf("Queue is empty!\n");
		return;
	}
	else if(front==rear)
	{
        front=rear=NULL;
	}else
	{
		front=front->link;
	}
    printf("Dequeue : %d\n", temp->data);
	free(temp);
}

void display()
{
	struct node* temp;
	temp= front;

	if(front==NULL)
	{
		printf("Queue is empty\n");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("\t%d\n", temp->data);
			temp=temp->link;
		}
	}
}

void main()
{
	int ch;
	printf("Queue operations,\n");

	while(1)
	{
		printf("\t1.Enqueue\n\t2.Dequeue\n\t3.Display\n\t4.Quit\nEnter choice :");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1:
			{
				enqueue();break;
			}
			case 2:
			{
				dequeue();break;
			}
			case 3:
			{
				display();break;
			}
			default :
			{
				printf("\nQUIT!!");
				exit(1);
			}
		}
	}
}