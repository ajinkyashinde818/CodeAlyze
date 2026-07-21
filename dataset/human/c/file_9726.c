#include<stdio.h>
#include<stdlib.h>
#define N 100000
#define NIL -1

struct Node {int p,l,r;};
struct Node T[N];

int getDepth(u){
  int d = 0;
  while(T[u].p != NIL){
    u = T[u].p;
    d++;
  }
  return d;
}

void printChildren(u){
  int c = T[u].l;
  while(c != NIL){
    if(T[c].r == NIL) printf("%d",c);
    else printf("%d, ",c);
    c = T[c].r;
  }
}

int main(){
  int n,i,j,d,v,c,l,r;
  
  scanf("%d",&n);

  for(i = 0; i < n; i++){
    T[i].p = NIL;
    T[i].l = NIL;
    T[i].r = NIL;
  }

  for(i = 0; i < n; i++){
    scanf("%d%d",&v,&d);
    for(j = 0; j < d; j++){
      scanf("%d",&c);
      if(j == 0) T[v].l = c;
      else T[l].r = c;
      l = c;
      T[c].p = v;
    }
  }
  for(i = 0; i < n; i++){
    if(T[i].p == NIL) r = i;
  }
  for(i = 0; i < n; i++){
    printf("node %d: parent = %d, depth = %d, ",i,T[i].p,getDepth(i));
    if(T[i].p == NIL) printf("root, ");
    else if(T[i].l == NIL) printf("leaf, ");
    else printf("internal node, ");
    printf("[");
    printChildren(i);
    printf("]\n");
    
  }

}
