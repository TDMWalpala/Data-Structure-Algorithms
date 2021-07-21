#include <stdio.h>
#include <stdlib.h>
#define MAX 4
int count=0, front =0, rear = 0, CQ[MAX];
//INSERT
void insertCQ()
{
    int data;
    if(count == MAX)
    {
        printf("\nCircular Queue is Full");
    }
    else
    {
        printf("Enter Data : ");
        scanf("%d", &data);
        CQ[rear] = data;
        rear = (rear + 1) % MAX;
        count++;
        printf("\nData inserted in the circular queue.");
    }
}

//DELETE
void deleteCQ()
{
    if(count == 0)
    {
        printf("\nCircular Queue is Empty");
    }
    else
    {
        printf("Deleted element from circular Queue is %d ", CQ[front]);
        front = (front + 1)%MAX;
        count--;
    }
}

//DISPLAY
void displayCQ()
{
    int i, j;
    if(count == 0)
    {
        printf("\nCircular Queue is Empty");
    }else
    {
        printf("\n Elements in circular Queue are :");
        j = count;
        for(i=front; j!=0; j--)
        {
            printf("%d ",CQ[i]);
            i = (i+1)%MAX;
        }
    }
}


int main()
{

    int n;
    printf("\n<<Circular Queue Operations>>");
    printf("\n\t1. INSERT\n\t2. DELETE\n\t3. DISPLAY\n\t4. QUIT ");
    do
    {
        printf("\nEnter Your Choice : ");
        scanf("%d", &n);
        switch(n)
        {
        case 1:
            {
                insertCQ();break;
            }

         case 2:
            {
                deleteCQ();break;
            }
         case 3:
            {
                displayCQ();break;
            }
         case 4:
            {
                printf("\n*****QUIT****");break;
            }
        }
    }while(n!=4);

    getch();
}
