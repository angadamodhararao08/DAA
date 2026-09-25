#include<stdio.h>
#define MAX 6
int parent[MAX];
void init(){
  int i;
  for(i=0;i<MAX;i++){
    parent[i]=-1;
  }
}
int find(int x){
  if(parent[x]<0)
    return x;
  parent[x]=find(parent[x]);
  return parent[x];
}
void unionSet(int x,int y){
  int rootX=find(x);
  int rootY=find(y);
  if(rootX==rootY)
    return;
  parent[rootY]=rootX;
}
void printState(){
  int i;
  for(i=0;i<MAX;i++){
    printf("%3d",parent[i]);
  }
}
int main(){
    int i,u,v;
    int rootU,rootV;
    init();
    //create set1:0<-1<-2
    parent[1]=0;//1's parent is 0
    parent[2]=1;//2's paremt is 1
    //parent[0] remains -1(root)
    //create set2:3<-4 and 3<-5
    parent[4]=3;
    parent[5]=3;
    //parent[3] reamins -1
    printf("\n===Initial State===\n");
    printState();
    printf("\nNow testing edge(2,3):\n");
    u=2;v=3;
    printf("Edge:(%d %d)\n",u,v);
    printf("Find(%d):",u);
    rootU=find(u);
    printf("Root=%d\n",rootU);
    printf("Find(%d):",v);
    rootV=find(v);
    printf("Root=%d\n",rootV);
    printf("\nrootU=%d,rootV=%d\n",rootU,rootV);
    if(rootU==rootV){
      printf("\nDETECTED\n");
      printf("Edge(%d,%d) forms a cycle\n",u,v);
    }
    else{
        printf("No cycle found\n");
        printf("Adding Edge(%d,%d)....\n",u,v);
        unionSet(u,v);
        printf("\n===Sets after union===\n");
        printState();
        printf("\nFinal merged set:\n");
        printf("Root 0-> children:");
        for(i=0;i<MAX;i++){
          if(parent[i]==0)
            printf("%d\t",i);
        }
    }

}
