#include <stdio.h>
#include <stdlib.h>

struct node
{
	int coef;
	int exp;
	struct node *next;
};

struct node *getnode()
{
	struct node *p;
	p= (struct node*)malloc(sizeof(struct node));
	return p;
}

int insertbegin(struct node **list, int co, int ex)
{
	struct node *temp;
	temp = getnode();
	temp->coef=co;
	temp->exp=ex;
	temp->next=*list;
	*list=temp;
}

int insertend(struct node **list, int co, int ex)
{
	struct node *temp,*p;
	temp=*list;
	if(*list==NULL)
	{
		insertbegin(&(*list),co,ex);
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		p=getnode();
		p->coef=co;
		p->exp=ex;
		p->next=NULL;
		temp->next=p;
	}
}

int display(struct node *list)
{
	struct node*t;
	t=list;
	while(t!=NULL)
	{
		printf("\t%dX^%d +",t->coef,t->exp);
		t=t->next;
	}
}

struct node * addpoly(struct node *poly1, struct node *poly2)
{
	struct node *poly3=NULL;
	struct node *p,*q;
	p=poly1;
	q=poly2;

	while(p!=NULL && q!=NULL)
	{
		if(p->exp==q->exp)
		{
			insertend(&poly3,p->coef+q->coef,p->exp);
			p=p->next;
			q=q->next;
		}
		else
		{
			if(p->exp>q->exp)
			{
				insertend(&poly3,p->coef,p->exp);
				p=p->next;
			}
			else
			{
				insertend(&poly3,q->coef,q->exp);
				q=q->next;
			}
		}
	}
	while(p!=NULL)
	{
		insertend(&poly3,p->coef,p->exp);
		p=p->next;
	}
	while(q!=NULL)
	{
		insertend(&poly3,q->coef,q->exp);
		q=q->next;
	}

	return poly3;
}

void main()
{
	struct node *head1,*head2,*head3;
	head1=NULL;
	head2=NULL;
	head3=NULL;

	int x,c,e,i=0;

	while(1)
	{
		printf("\n1.Enter frist polynomial\n2.Enter second polynomial\n3.Display frist polynomial\n4.Display second polynomial\n5.Display sum of the two polynomial\n6.Quit\nEnter your choice :");
		scanf("%d", &x);

		switch(x)
		{
			case 1:
			{
				while(i!=1)
				{
					printf("Enter coef : ");
				    scanf("%d", &c);
				    printf("Enter Exponent : ");
				    scanf("%d", &e);
				    insertend(&head1,c,e);
				    printf("If you complete entered polynomial ? [1.Yes/2.No]\n");
				    scanf("%d", &i);
				}
				i=0;
				break;
				
			}
			case 2:
			{
				while(i!=1)
				{
					printf("Enter coef : ");
				    scanf("%d", &c);
				    printf("Enter Exponent : ");
				    scanf("%d", &e);
				    insertend(&head2,c,e);
				    printf("If you complete entered polynomial ? [1.Yes/2.No]\n");
				    scanf("%d", &i);
				}
				i=0;
				break;
			}
			case 3:
			{
				display(head1);
				break;
			}
			case 4:
			{
				 display(head2);
				break;
			}
			case 5:
			{
				head3=addpoly(head1,head2);

	            printf("\n\n");
	             display(head3);
	            break;
			}
			default :
			{
				exit(1);
			}
		}
	}

}