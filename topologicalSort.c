#include<stdio.h>
#include<stdbool.h>
#define MAX 20
int adj[MAX][MAX];
int stack[MAX];
int top=-1;
bool visited[MAX];
void dfs(int v,int n){
  int i;
  visited[v]=true;
  for(i=0;i<n;i++){
    if(adj[v][i]==1 && !visited[i])
        dfs(i,n);
  }
  stack[++top]=v;
}
void topologicalSort(int n){
  int i;
  for(i=0;i<n;i++){
    visited[i]=false;
  }
  for(i=0;i<n;i++){
    if(!visited[i])
        dfs(i,n);
  }
  printf("Topological Sort:");
  while(top>=0){
    printf("%d\t",stack[top--]);
  }
  printf("\n");
}
int main(){
  int n=6,i,j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        adj[i][j]=0;
    }
  }
  adj[5][2]=1;
  adj[5][0]=1;
  adj[4][0]=1;
  adj[4][1]=1;
  adj[2][3]=1;
  adj[3][1]=1;
  topologicalSort(n);
}
