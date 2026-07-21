#include<stdio.h>

#define MAX 10000
#define NIL -1

struct Node {
  int p,l,r;
};

struct Node T[MAX];

int n;
int D[MAX],H[MAX];

int main() {
  int i,v,l,r;

  scanf("%d",&n);
  for(i = 0 ; i < n ; i++) {
    T[i].p = NIL;
  }

  for(i = 0 ; i < n ; i++) {
    scanf("%d%d%d",&v,&l,&r);
    T[v].l = l;
    T[v].r = r;
    if ( l != NIL )
      T[l].p = v;
    if ( r != NIL )
      T[r].p = v;
  }

  for (i = 0 ; i < n ; i++){
    D[i] = getDepth(i);
    H[i] = 0;
  }

  for (i = 0 ; i < n ; i++){
    if (T[i].l == NIL && T[i].r == NIL) {
      H[i] = 0;
      int p = T[i].p;
      int c = 1;
      while(1){
        if (p == NIL)
          break;
        if (H[p] < c)
          H[p] = c;
        c++;
        p = T[p].p;
      }
    }
  }
  for (i = 0 ; i < n ; i++)
    print(i);
  return 0;
}


int getDepth(int x) {
  int d = 0;

  while(1) {
    x = T[x].p;
    if(x == NIL)
      break;
    d++;
  }
  return d;
}

int getSibling(int x) {
  if(T[x].p == NIL)
    return NIL;
  if(T[T[x].p].l != x && T[T[x].p].l != NIL)
    return T[T[x].p].l;
  if(T[T[x].p].r != x && T[T[x].p].r != NIL)
    return T[T[x].p].r;
  return NIL;
}

int print(int x){
  int degree = 0;

  printf("node %d: ", x);
  printf("parent = %d, ", T[x].p);
  printf("sibling = %d, ", getSibling(x));

  if ( T[x].l != NIL )
    degree++;
  if ( T[x].r != NIL )
    degree++;
  printf("degree = %d, ", degree);
  printf("depth = %d, ", D[x]);
  printf("height = %d, ", H[x]);

  if ( T[x].p == NIL ){
    printf("root\n");
  }
  else if ( T[x].l == NIL && T[x].r == NIL ){
    printf("leaf\n");
  }
  else {
    printf("internal node\n");
  }
}
