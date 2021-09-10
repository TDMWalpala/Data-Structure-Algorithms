#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int beginaddress; // beginning address
    int endaddress; // end of the address partition
    int processID; // if hole is false,It contains the process identifier of the process using the partition.Otherwise -1
    bool hole; // hole is false if it occupied by the process true otherwise

    struct node* left; // left pointer field
    struct node* right; // right pointer field
};

struct node* head = NULL; // head of the Partition List

int MMsize; // memory size

void MemoryInitialization() //Constructor that Initizialize Memory Process
{
    int OSMsize; // size of operating system memory
    printf("Please Assign a suitable memory for the task : ");
    scanf("%d", &MMsize); // get memory for the task
    printf("Please Assign memory block Operating System : ");
    scanf("%d", &OSMsize); // get memory for operating system

    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node)); // memory allocation for temp

    /*create a node*/
    temp->beginaddress=0;
    temp->endaddress=(OSMsize-1);
    temp->processID=0;
    temp->hole=false;

    temp->left=NULL;
    temp->right=NULL;

    head = temp; // temp node pointed to head

    struct node* p;
    p = (struct node*)malloc(sizeof(struct node)); // memory allocation for p

    head->right = p; // p node pointed to head->right

    p->beginaddress = head->endaddress+1 ;
    p->endaddress =MMsize;
    p->processID = -1;
    p->hole=true;

    p->left=head;
    p->right=NULL;
}

void addprocess() //Constructor that allots memory block
{
     int Msize,PID;
     printf("Enter Memory Size :");
     scanf("%d", &Msize); // get memory size for relevant task
     printf("Process ID :P");
     scanf("%d", &PID); // get process ID

     struct node* temp,*p,*q;

    temp = head;

    p = (struct node*)malloc(sizeof(struct node));
    bool flag = true;

    while(temp!=NULL)
    {
        if(temp->hole && (temp->endaddress-temp->beginaddress)>=Msize && temp->processID==-1 && Msize<=MMsize && flag)
        {
            temp->processID = PID;
            temp->hole = false;
            temp->beginaddress = temp->left->endaddress+1;
            temp->endaddress= temp->beginaddress+Msize-1;
            flag = false;
        }
        temp=temp->right;
    }
     temp = head;

     /*create a node*/
     p = (struct node*)malloc(sizeof(struct node));
          p->beginaddress = temp->beginaddress+Msize;
          p->endaddress = MMsize;
          p->hole=true;
          p->processID = -1;
          p->left=NULL;
          p->right=NULL;
     while(temp->right!=NULL)
    {

        temp=temp->right;
        p->beginaddress = temp->beginaddress+Msize;
    }
          temp->right = p;
          p->left=temp;
          p->right = NULL;

          q=head;
          while(q->right!=NULL)
          {
              if(q->right->beginaddress - q->endaddress >1)
              {

                  struct node* temp;
                  /*create a node*/
                  temp = (struct node*)malloc(sizeof(struct node));

                  temp->processID = -1;
                  temp->hole = true;
                  temp->beginaddress = q->endaddress+1;
                  temp->endaddress= q->right->beginaddress-1;
                  temp->left = NULL;
                  temp->right =NULL;

                  temp->right = q->right;
                  temp->left = q;
                  q->right = temp;
                  q->right->left = temp;


              }
              q = q->right;
          }

} // end of a addProcess constructor

void RemvProcess(int PID) // Constructor that removes the assigned memory blocks
{
    struct node* temp;
    temp = head;

    while(temp->processID!=PID)
    {
        temp = temp->right;

    }
    temp->processID = -1;
    temp->hole = true;
} // end of Remove Process Constructor

void MergeMemoryBlock() //Constructor that Merge the Memory blocks
{
    struct node* temp;
    temp = head;
    bool flag2 = true;

    while(temp->right!=NULL)
    {

        if(temp->hole && temp->right->hole)
        {
            temp->right->beginaddress = temp->beginaddress;
            temp->left->right = temp->right;
            temp->right->left = temp->left;

            free(temp);
        }
     temp=temp->right;
    }
} // end of memory merge constructor

void display() // Constructor that constructs display the output
{

    struct node* temp;
    temp = head;

    while(temp!=NULL)
    {
        printf("\t+-------+-------+-------+-------+\n");
        if(temp->processID==0)
        {
             printf("\t| %dK\t",temp->beginaddress);
             printf("| %dK\t",temp->endaddress);
             printf("| OS\t");
             printf("|   %d\t|\n",temp->hole);
        }
        else if(temp->processID==-1)
        {
             printf("\t| %dK\t",temp->beginaddress);
             printf("| %dK\t",temp->endaddress);
             printf("| FREE\t");
             printf("|   %d\t|\n",temp->hole);
        }
        else
        {
             printf("\t| %dK\t",temp->beginaddress);
             printf("| %dK\t",temp->endaddress);
             printf("| P%d\t",temp->processID);
             printf("|   %d\t|\n",temp->hole);
        }


        temp=temp->right;
    }
    printf("\t+-------+-------+-------+-------+\n");

} //end of print partition constructor



void main()
{

    int choice; // User choice
    int PID; // process ID

    MemoryInitialization();
    MergeMemoryBlock();
    while(1)
    {
      printf("To add process press 1 to Delete 2 else EXIT.\n");
      scanf("%d", &choice);

      switch(choice)
      {
         case 1:
             {
                 addprocess();MergeMemoryBlock();display();break;
             }

         case 2:
             {
                 printf("Enter Process ID : P");
                 scanf("%d", &PID);
                 RemvProcess(PID); MergeMemoryBlock();display();break;
             }
         default :
            {
                exit(1);break;
            }
      }

    }
}
