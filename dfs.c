//Program to perform dfs algorithm for graph traversal
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_VERTICES 10
struct Graph{
  int numVertices;
  bool visited[MAX_VERTICES];
  int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};
struct Graph* createGraph(int vertices){
  int i,j;
  struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
  graph->numVertices=vertices;
  for(i=0;i<vertices;i++){
    graph->visited[i]=false;
    for(j=0;j<vertices;j++){
      graph->adjMatrix[i][j]=0;
    }
  }
  return graph;
}
void addEdge(struct Graph*graph,int src,int des){
  graph->adjMatrix[src][des]=1;
  graph->adjMatrix[des][src]=1;
}
//dfs process
void dfs(struct Graph*graph,int startVertex){
  int currentVertex;
  int stack[MAX_VERTICES];
  int top=-1;
  //mark the starting as visited
  graph->visited[startVertex]=true;
  stack[++top]=startVertex;
  printf("DFS Traversal staring from vertex %d:",startVertex);
  while(top>=0){
    //pop a vertex from stack
    int i;
    currentVertex=stack[top--];
    printf("%d\t",currentVertex);
    //look at the potential neighbours in the matrix
    for(i=0;i<graph->numVertices;i++){
        if(graph->adjMatrix[currentVertex][i]==1&& !graph->visited[i]==true){
            graph->visited[i]=true;
            stack[++top]=i;
        }
    }
  }
  printf("\n");
}
int main(){
  int vertices=6,s;
  struct Graph*graph=createGraph(vertices);
  //creating a sample connected graph
  addEdge(graph,0,1);
  addEdge(graph,0,2);
  addEdge(graph,1,3);
  addEdge(graph,1,4);
  addEdge(graph,2,4);
  addEdge(graph,3,5);
  addEdge(graph,4,5);
  //execute dfs
  printf("Enter the starting vertex:");
  scanf("%d",&s);
  dfs(graph,s);
  free(graph);
  return 0;
}

