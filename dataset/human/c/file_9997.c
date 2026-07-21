#include<stdio.h>

#define N 100000
#define NIL -1

struct Node{int p,l,r;};

struct Node T[N];
int D[N]; //store each Depth

void print(int);
int rec(int,int);

int main(void){
  int n,k,v,d,b,r,l;
  int i,j;

  scanf(" %d",&n);
  for(i = 0; i < n; i++){
    T[i].p = T[i].l = T[i].r = NIL;
  }

  for(i = 0; i < n; i++){
    scanf(" %d",&v);
    scanf(" %d",&d);
    for(j = 0; j < d; j++){
      scanf(" %d",&b);
      if(j == 0) T[v].l = b;
      else T[l].r = b;
      l = b;
      T[b].p = v;
    }
  }

  for(i = 0; i < n; i++){
    if(T[i].p == NIL) r = i;
  }

  rec(r,0);


  for(i = 0; i < n; i++) print(i);
  
  return 0;
}

void print(int u){
  int i,c;
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].p);
  printf("depth = %d, ",D[u]);

  if(T[u].p == NIL) printf("root, ");
  else if(T[u].l == NIL) printf("leaf, ");
  else printf("internal node, ");

  printf("[");
  for(i = 0, c = T[u].l; c != NIL; i++, c = T[c].r){
    if(i) printf(", ");
    printf("%d",c);
  }
  printf("]\n");
}

int rec(int u, int p){
  D[u] = p;
  if(T[u].r != NIL) rec(T[u].r,p);
  if(T[u].l != NIL) rec(T[u].l,p+1);
}
