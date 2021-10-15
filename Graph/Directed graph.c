#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool flag = false;
bool flag2 = true;

struct node {
  int vertex;
  struct node* next;
};
struct node* createNode(int);

struct Graph {
  int numVertices;
  struct node** adjLists;
};

// Create a node
struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

// Create a graph
struct Graph* createAGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));

  int i;
  for (i = 0; i < vertices; i++)
    graph->adjLists[i] = NULL;

  return graph;
}

// Add edge
void addEdge(struct Graph* graph, int s, int d) {
  // Add edge from s to d
  struct node* newNode = createNode(d);
  newNode->next = graph->adjLists[s];
  graph->adjLists[s] = newNode;

}

// Print the graph
void printGraph(struct Graph* graph) {
  int v;
  if(flag)
  {

  for (v = 0; v < graph->numVertices; v++) {
    struct node* temp = graph->adjLists[v];
    if(graph->adjLists[v]==1)
    {
        printf("\n Vertex %d\n: ", v);
    }


    if(graph->adjLists[v]!=NULL && graph->adjLists[v] != 1)
    {
        printf("\n Vertex %d\n: ", v);
        while (temp) {
        printf("%d -> ", temp->vertex);
        temp = temp->next;
        }
        printf("\n");
    }

   }
  }
  else
  {
    int i=0;

    for (v = 0; v < graph->numVertices; v++) {
    struct node* temp = graph->adjLists[v];

    printf("\n Vertex %d\n: ", v);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");


  }
  flag = true;
  }

}

//delete vertex
void deletevertex(struct Graph* graph){

  int n,Location,i,choice;
  int v;
  while(flag2)
  {
      printf("\n\tFor Delete Vertex, press 1\n\telse Quit.");
      scanf("%d",&choice);
      if(choice==1)
      {
          printf("Enter vertex :");
          scanf("%d",&n);

     struct node* temp = graph->adjLists[n];
     graph->adjLists[n]=NULL;


     for (v = 0; v < graph->numVertices; v++){
     Location=0;
     struct node* temp = graph->adjLists[v];
     struct node* p = graph->adjLists[v];
     if(graph->adjLists[v]!=NULL)
     {
        i = 1;
        while (temp){
                if(temp->vertex==n)
                {
                    Location=i;
                    if(Location==1 && temp->next==NULL)
                    {
                       graph->adjLists[v] = 1;

                    }
                    else if(Location==1 && temp->next!=NULL)
                    {
                        graph->adjLists[v] = temp->next;

                    }
                    else if(Location>1)
                    {
                        int x=0;
                        while(x==Location-1)
                        {
                            p = p->next;
                            x++;
                        }
                        p->next = temp->next;
                        temp->next=NULL;
                    }
                }
                i++;
                temp = temp->next;
        }
      }
      if(graph->adjLists[v]==NULL && v!=n)
      {
        graph->adjLists[v] = 1;

      }
   }
   printGraph(graph);
      }
      else
      {
          flag2=false;
      }
  }

}

int main(){
  struct Graph* graph = createAGraph(5);

  addEdge(graph, 0, 1);
  addEdge(graph, 2, 1);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 4);
  addEdge(graph, 3, 1);
  addEdge(graph, 4, 1);
  addEdge(graph, 4, 0);

  printGraph(graph);
  deletevertex(graph);

  return 0;
}
