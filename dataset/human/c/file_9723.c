#include<stdio.h>
#include<stdlib.h>
 
#define MAX 1000000
 
typedef struct{
  int parent;
  int left;
  int right;
}Node;
 
void RootedTree(int);
Node T[MAX];
 
int main(){
  int n,i,j;
  int k,id,child,x,depth;
 
  scanf("%d",&n);
 
  for(i=0;i<n;i++){
    T[i].parent=-1;
    T[i].left=-1;
    T[i].right=-1;
  }
 
  for(i=0;i<n;i++){
    scanf("%d%d",&id, &k);
    for(j=0;j<k;j++){
      scanf("%d",&child);
      T[child].parent=id;
      if(j==0) T[id].left=child;
      else if(j>0) T[x].right=child;
      x=child;
    }
  }
 
  for(i=0;i<n;i++) RootedTree(i);
  return 0;
}
 
void RootedTree(int n){
  int i=T[n].parent;
  int depth=0;
 
  while(i!=-1){
    i = T[i].parent;
    depth++;
  }
 
  if(depth == 0) printf("node %d: parent = %d, depth = %d, root, ",n ,T[n].parent, depth);
  else if(T[n].left == -1) printf("node %d: parent = %d, depth = %d, leaf, ",n ,T[n].parent, depth);
  else printf("node %d: parent = %d, depth = %d, internal node, ",n ,T[n].parent, depth);
 
  i=T[n].left;
  printf("[");
  if(i!=-1) printf("%d",i);
 
  while(i!=-1){
    i=T[i].right;
    if(i!=-1) printf(", %d",i);
  }
  printf("]\n");
}
