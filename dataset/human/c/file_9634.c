#include <stdio.h>
#include <stdlib.h>
#define N 100000
#define M 100000

int parentSearch(int);
int depthSearch(int); 
char *Treejudge(int);

int n,node;
int k[N];
int *c[M];
int parent[N];
int depth[N];
char *Tree[N];

int main(){
  int i,j;


  scanf("%d",&n);
  if(n>N)exit(8);
  for(i=0 ; i<N ; i++){
    parent[i]=-1;
  }
  for(i=0 ; i<n ; i++){
    scanf("%d",&node);
    scanf("%d",&k[node]);
    c[node]=(int *)malloc(sizeof(int)*k[node]);
    for(j=0 ; j<k[node] ; j++){
      scanf("%d",&c[node][j]);
      parent[c[node][j]]=node;
    }
  }

 
  for(i=0 ; i<n ; i++){
    depth[i]=depthSearch(parent[i]); 
  }
  for(i=0 ; i<n ; i++){
    Tree[i]=Treejudge(i);
  }


    for(i=0 ; i<n ; i++){
      printf("node %d: parent = %d, depth = %d, %s, ",i,parent[i],depth[i],Tree[i]);
      printf("[");
      for(j=0 ; j<k[i] ; j++){
	printf("%d",c[i][j]);
	if(j==k[i]-1)break;
	printf(", ");
      }
      printf("]\n");
    }

      return 0;
}
    
int depthSearch(int Nodeparent){
  int i,depth=0;
  
  while(Nodeparent != -1){
      depth++;
      Nodeparent = parent[Nodeparent];
  }
  return depth;
}

char *Treejudge(int Node){
  int i;
  if(parent[Node]==-1)return "root";
    if(k[Node]>0)return "internal node";
  return "leaf";
}
