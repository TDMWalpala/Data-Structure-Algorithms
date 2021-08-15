#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* link;
};

struct node* top = NULL;

void push()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter a value: ");
	scanf("%d", &temp->data);

	temp->link=top;
	top=temp;
}

void pop()
{
	struct node* temp;
	if(top==NULL)
	{
		printf("stack is empty\n");
	}
	else
	{
		temp=top;
		printf("Element %d is poped.\n", temp->data);
		top=top->link;
		temp->link = NULL;
		free(temp);
	}
}

void display()
{
	struct node* temp;
	if(top==NULL)
	{
		printf("No element to display\n");
	}
	else
	{
		temp=top;
		printf("Element in the stack : \n");
		while(temp!=NULL)
		{
			printf("\t%d\n",temp->data);
			temp = temp->link;
		}
	}
}

void peek()
{
	struct node *temp;
	if(top==NULL)
	{
		printf("stack is empty\n");
	}
	else
	{
		temp=top;
	    printf("Peek : %d\n", temp->data);
	}
	
}

int main()
{
	int ch;
	
	while(1)
	{
		printf("stack operations.\n");
		printf("\n\t1.PUSH\n\t2.POP\n\t3.PEEK\n\t4.DISPLAY\n\t5.EXIT\n");
		printf("\nEnter operation Number :");
		scanf("%d", &ch);
        
		switch(ch)
		{
			case 1:
			{
				push();break;
			}
			case 2:
			{
				pop();break;
			}
			case 3:
			{
				peek();break;
			}
			case 4:
			{
				display();break;
			}
			default :
			{
				printf("EXIT!\n");
				exit(1);
			}
		}
	}
	return 0;
}