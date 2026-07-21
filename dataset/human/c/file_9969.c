#include<stdio.h>

#define MAX 100000
#define NIL -1

struct Type{ 
  int p, l, r;
};
struct Type A[MAX];

int n,D[MAX];

int getDepth(int u){
  int d = 0;

  while(A[u].p!=NIL){
    u=A[u].p;
    d++;
  }
  return d;
}

void print(int u){
  int i;
  printf("node %d: parent = %d, depth = %d, ",u,A[u].p,D[u]);
  if(A[u].p==NIL) printf("root, ");
  else if(A[u].l==NIL) printf("leaf, ");
  else if(A[u].l!=NIL) printf("internal node, ");
  printf("[");
  if(A[u].l!=NIL){
    printf("%d",A[u].l);
    u=A[u].l;
    if(A[u].r!=NIL) printf(", ");
    
    while(A[u].r!=NIL){
      printf("%d",A[u].r);
      u=A[u].r;
      if(A[u].r!=NIL) printf(", ");
    }
  }
  printf("]\n");
}

main(){
  int i, j, d, v, c, l;
  scanf("%d", &n);
  for(i=0;i<n;i++) {
    A[i].p=NIL;
    A[i].l=NIL;
    A[i].r=NIL;
  }
  for(i=0;i<n;i++){
    scanf("%d %d", &v, &d);
    for(j=0;j<d;j++){
      scanf("%d", &c);
      A[c].p=v;
      if(j==0) A[v].l=c;
      if(j>0) A[l].r=c;
      l=c;
    }
  }
  for(i=0;i<n;i++){
    D[i]=getDepth(i);
  }
  for(i=0;i<n;i++)print(i);
  return 0;
}
