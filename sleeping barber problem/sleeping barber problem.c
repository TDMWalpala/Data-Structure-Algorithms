#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int MAX; // number of chairs

struct node{
    int customerNumber; // customer number
    struct node* next; // pointer to the next node
};

struct node* front = NULL;
struct node* rear = NULL;

int customercount=0; // customer count
bool flag2; // declare flag2

void Client_Comes() /*customer comes barber shop*/
{
    if(customercount<=MAX-1)
    {
         customercount++; // increases customer count by 1
         int static cnum; //declare customer number // Static variables are initialized only once
         cnum++; // increase customer number by 1
         printf("\nCustomer %d comes shop.\n\n", cnum);
         struct node *temp;
         temp = (struct node*)malloc(sizeof(struct node)); // allocate a new node in a heap
         // set data in the allocated node
         temp->customerNumber = cnum;
         temp->next=NULL;

         if(front==NULL && rear==NULL)
         {
    	     front=temp;
             rear=temp;
             flag2=true;
         }
         else
         {
    	    rear->next=temp;
            rear=temp;
         }
    }
    else
    {
        printf("\nClient leaves, because no chair available in the shop.\n\n");
        flag2 = false;
    }
}

void Client_Leaves() /*customer leave barber shop*/
{
	struct node* temp;
	temp=front;
	if(front==NULL) // if the barber shop becomes empty
	{
		printf("No Clients!\n");
		return;
	}
	else if(front==rear)
	{
        front=rear=NULL;
	}else
	{
		front=front->next;
	}
    printf("\nClient Number %d leaves shop.\n\n", temp->customerNumber);
	free(temp); // deallocate the memory of the removed node
	customercount--; //decreases customer count by 1
}

void Current_Status_In_Shop()
{
    int count=0; //declare count
    struct node* temp;
	temp= front;

	if(front==NULL)
	{
		printf("\nBarber is sleeping because there are no clients.\n\n");
		flag2 = true;
	}
	else
	{
	    bool flag = true;
		while(temp!=NULL) // check barber shop
		{
		    if(flag)
            {
                if(flag2)
                {
                    printf("_/ (Barber sleeping) Hey barber wake up!\n\n");
                    flag2 = false;
                }
                printf("_/%d (Barber is busy)  ", temp->customerNumber); // print customer in barber room
                flag = false;
            }
            else
            {
               printf("]_%d (Waiting) ", temp->customerNumber); // print waiting customer

            }
			count++;  // increases count by 1
			temp=temp->next;
		}
	}

    for(int i=count; i<MAX;i++)
    {
           printf("]_ "); // print empty chairs
    }
    printf("\n\n");
}

void main()
{
    //system("COLOR 80");
	int ch; // declare ch
	printf("\t|++++Sleeping barber programm++++|\n\n");

	printf("Enter number of chairs in customer waiting room : ");
	scanf("%d", &MAX); // input number of chairs for customer waiting room
	MAX+=1; // MAX +1 (added one more chair for barber)

	while(1)
	{
		printf("\t1.Client comes to the barber shop.\n\t2.Barber finishes haircut his current client.\n\t3.Close the shop.\n\nEnter choice :");
		scanf("%d", &ch); // input user choice

		switch(ch)
		{
			case 1: // ch = 1
			{
				Client_Comes();Current_Status_In_Shop();break; // calling Client_Comes and Current_Status_In_Shop fuctions
			}
			case 2: // ch = 2
			{
				Client_Leaves();Current_Status_In_Shop();break; // calling Client_Leaves and Current_Status_In_Shop functions
			}
			case 3: // ch = 3
			{
				printf("\nBarber shop is close!!");
				exit(1);break;
			}
			default :
			{
				printf("\nPlease enter correct input!\n");
			}
		}
	}
}
