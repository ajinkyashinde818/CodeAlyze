#include<stdio.h>
#define MAX 100005
#define NIL -1

struct NODE{
  int parent,left,right;
};
struct NODE T[MAX];
int n,D[MAX];

int getDepth(int u){
  int d = 0;
  while(T[u].parent != NIL){
    u = T[u].parent;
    d++;
  }
  return d;
}

void printChildren(int u){
  int c;
  c = T[u].left;
  printf("[");
  while(c != NIL){
    printf("%d",c);
    c = T[c].right;
    if(c != NIL)printf(", ");
  }
  printf("]\n");
}

int main(){
  int i,j,d,v,c,l,r;
  
  scanf("%d",&n);
  
  for(i = 0 ; i < n ; i++){
    T[i].parent = NIL;
    T[i].left = NIL;
    T[i].right = NIL;
  }
  
  for(i = 0 ; i < n ; i++){
    scanf("%d",&v);
    scanf("%d",&d);
    for(j = 0 ; j < d ; j++){
      scanf("%d",&c);
      if(j == 0)T[v].left = c;
      else T[l].right = c;
      l = c;
      T[c].parent = v;
    }
  }
  
  for(i = 0 ; i < n ; i++){
    if(T[i].parent == NIL)r = i;
  }

  for(i = 0 ; i < n ; i++){
    printf("node %d: ",i);
    printf("parent = %d, ",T[i].parent);
    printf("depth = %d, ",getDepth(i));
    if(T[i].parent == NIL)printf("root, ");
    else if(T[i].left == NIL)printf("leaf, ");
    else printf("internal node, ");
    printChildren(i);    
  }
  
  return 0;
}
