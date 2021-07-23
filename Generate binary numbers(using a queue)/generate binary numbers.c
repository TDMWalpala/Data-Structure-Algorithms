#include <stdio.h>
#include <string.h>
#define MAX 20
char queue[MAX][MAX], temp1[MAX];
int front = -1, rear = -1;

void enqueue(char *ptr)
{
    if(rear == MAX-1)
    {
      printf("\nQueue is overflow");
      return;
    }
    if(front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear = rear + 1;

    }
 strcpy(queue[rear],ptr);
}

char* dequeue()
{
   if(front == -1)
   {
      printf("\nEmpty Queue");
   }
   else
   {
     strcpy(temp1,queue[front]);
     if(front == rear)
     {
        front = rear = -1;
     }
     else
     {
        front = front + 1;

     }
   return temp1;
   }
}

void binary()
{
    char temp2[MAX];
    strcpy(temp1,dequeue());
    printf("%s\n",temp1);
    strcpy(temp2,temp1);
    strcat(temp1,"0");
    enqueue(temp1);
    strcat(temp2,"1");
    enqueue(temp2);
}

int main()
{
   int i,n;
   printf("\nEnter the end value : ");
   scanf("%d",&n);
   char temp1[2] = "1";
   enqueue(temp1);
   printf("\nBinary numbers from 1 to %d : \n",n);
   for(i = 1; i <= n; i++)
   {
         binary();
   }
return 0;
}
