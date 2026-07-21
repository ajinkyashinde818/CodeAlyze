#include<stdio.h>
#define MAX 10000
#define NIL -1
#define t 1

struct Node
{
  int p, q, r;
};

struct Node T[MAX];

int n,D[MAX],H[MAX];

int getdepth(int u){
  int d1=0;
  while(t){
    u = T[u].p;
    if(u == NIL){
      break;
    }
    d1++;
  }
  return d1;
}

int getsibling(int u)
{
  if(T[u].p == NIL) {
    return NIL;
  }
  if(T[T[u].p].q != u && T[T[u].p].q != NIL) {
    return T[T[u].p].q;
  }
  if(T[T[u].p].r != u && T[T[u].p].r != NIL){
    return T[T[u].p].r;
  }

  return NIL;
}

void print(int u)
{
  int d2=0;

  printf("node %d: parent = %d, sibling = %d,",u,T[u].p,getsibling(u));
  if( T[u].q != NIL ){
    d2++;
  }
  if( T[u].r != NIL ) {
    d2++;
  }
  printf(" degree = %d, depth = %d, height = %d, ", d2,D[u],H[u]);

  if( T[u].p == NIL ){
    printf("root");
    printf("\n");
  }
  else if( T[u].q == NIL && T[u].r == NIL){
    printf("leaf");
    printf("\n");
  }
  else{
    printf("internal node");
    printf("\n");
  }
}

int main()
{
  int i,v,q,r,p,C;

  scanf("%d", &n);
  for(i=0; i<n; i++){
    T[i].p = NIL;
  }

  for(i=0; i<n; i++){
    scanf("%d%d%d",&v,&q,&r);
    T[v].q = q;
    T[v].r = r;

    if(q != NIL){
      T[q].p = v;
    }
    if(r != NIL){
      T[r].p = v;
    }
  }

  for (i=0; i<n; i++){
    D[i] = getdepth(i);
    H[i] = 0;
  }

  for (i=0; i<n; i++){
    if(T[i].q == NIL && T[i].r == NIL){
      H[i] = 0;
      p = T[i].p;
      C = 1;

      while(t){
        if(p == NIL){
          break;
        }
        if(H[p] < C){
          H[p] = C;
        }
        C++;
        p = T[p].p;
      }
    }
  }

  for (i=0; i<n; i++){
    print(i);
  }

  return 0;
}
