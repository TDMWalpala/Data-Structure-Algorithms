#include <stdio.h>
#include <stdlib.h>
int size, choice,ele, i;
//creating queue
struct queue{
    int array[10];
    int front;
    int real;
}qu;
//enqueue
void enqueue(int ele)
{
    if(qu.real == size-1)
    {
        printf("Queue is full");
    }else
    {
        qu.real++;
        printf("Enter the element ");
        scanf("%d", &ele);
        qu.array[qu.real] = ele;
    }
}
//dequeue
int dequeue()
{
    if(qu.real == -1)
    {
        printf("Queue is empty");
    }else
    {
        int out;
        out = qu.array[qu.front];
        qu.front++;
        return out;
    }
}

//pekk
int peek()
{
    if(qu.real == -1)
    {
        printf("Queue is empty");
    }else
    {
        int display;
        display = qu.array[qu.front];
        return display;
    }
}
//display
void display()
{
    if(qu.real >=0)
    {
        printf("\n The elements in the queue ");
        for(i=qu.front; i<=qu.real; i++)
        {
            printf("\n%d", qu.array[i]);
        }
    }else
    {
      printf("\nQueue is empty");
    }
}
int main()
{
    qu.front= 0;
    qu.real = -1;
    printf("Enter a size for the queue of max 100");
    scanf("%d", &size);
    printf("\n\tFunction of Queue");
    printf("\n\t1.Enqueue\n\t2.Dequeue\n\t3.Peek\n\t4.Display\n\t5.Exit");
    do{
        printf("\nEnter your choice ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            {
                //insert
                enqueue(ele);break;
            }
        case 2:
            {
                //remove
                printf("%d", dequeue());break;
            }
        case 3:
            {
                //peek
                printf("%d", peek());break;
            }
        case 4:
            {
                //diplay
                display();break;
            }
        case 5:
            {
                //exit
                printf("Exit Queue");break;
            }
        default :
            {
                printf("\nEnter correct choice (1,2,3,4,5)");
            }

        }
    }while(choice!=5);
    return 0;
}
