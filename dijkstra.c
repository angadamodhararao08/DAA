#include<stdio.h>
#include<stdbool.h>
#define INF 9999
#define V 6
int findMinDistance(int dist[],bool visited[]){
  int min=INF,min_index,i;
  for(i=0;i<V;i++){
    if(!visited[i] && dist[i]<=min){
      min=dist[i];
      min_index=i;
    }
  }
  return min_index;
}
void printPath(int parent[],int i){
  int j=i;
  while(j!=-1){
    printf("%d<- ",j);
    j=parent[j];
  }
}
void dijkstra(int graph[V][V],int src){
  int i,v,count;
  int dist[V];
  bool visited[V];
  int parent[V];
  for(i=0;i<V;i++){
    dist[i]=INF;
    visited[i]=false;
    parent[i]=-1;
  }
  dist[src]=0;  //distance of source is always 0
  for(count=0;count<V-1;count++){
    int u=findMinDistance(dist,visited);
    visited[u]=true;
    for(v=0;v<V;v++){
        if(!visited[v] && graph[u][v] && dist[u]!=INF && dist[u]+graph[u][v]<dist[v]){
            dist[v]=dist[u]+graph[u][v];
            parent[v]=u;
        }
    }
  }
  printf("Vertex\tDistance\tPath\n");
  for(i=0;i<V;i++){
    printf("%d->%d\t%d\t\t",src,i,dist[i]);
    printPath(parent,i);
    printf("\n");
  }
}
int main(){
  int graph[V][V]={
    {0,10,5,0,0,0},
    {10,0,2,15,0,0},
    {5,2,0,0,3,0},
    {0,15,0,0,4,10},
    {0,0,3,4,0,2},
    {0,0,0,10,2,0},
  };
  dijkstra(graph,0);
  return 0;
}
