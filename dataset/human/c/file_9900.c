#include <stdio.h>
#define MAX 100005
#define NIL -1

struct Node {int p,l,r;};

struct Node  T[MAX];
int n,D[MAX];

void print(int u){
  int i,c;

  printf("node %d: ",u);
  printf("parent = %d,",T[u].p);
  printf(" depth = %d, ",D[u]);


  if(T[u].p == NIL) printf("root, ");
  else if (T[u].l == NIL) printf("leaf, ");
  else printf("internal node, ");

  printf("[");
  for(i=0,c=T[u].l;c!=NIL;i++,c=T[c].r){
    if(i) printf(", ");
    printf("%d",c);
  }
  printf("]\n");

}

int rec(int u,int p){
  D[u] = p;
  if(T[u].r != NIL) rec(T[u].r,p);
  if(T[u].l != NIL) rec(T[u].l,p+1);
}

int main(){

  int n,i,j,num,node,nodenum,c,left,right;
  
  scanf("%d",&n);
  for(i=0;i<n;i++) T[i].p = T[i].l = T[i].r = NIL;

  for(i = 0;i<n;i++){
    scanf("%d %d",&node,&nodenum);
    for(j=0;j<nodenum;j++){
      if(nodenum == 0) break;
      scanf("%d",&c);
      if(j == 0) T[node].l = c;
      else T[left].r = c;
      left = c;
      T[c].p = node;
    }
  }
  for(i=0;i<n;i++) if(T[i].p == NIL) right = i;

  rec(right,0);
 
  for(i=0;i<n;i++) print(i);
    return 0;
}
