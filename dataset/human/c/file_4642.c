#include<stdio.h>
#define MAX 10000
#define NIL -1

struct Node{
  int p, l, r;
};

struct Node T[MAX];
int n;
int D[MAX], H[MAX];

int getDepth(int u){
  int d = 0;
  while(1){
    u = T[u].p;
    if ( u == NIL ) break;
    d++;
  }
  return d;
}

int getSibling(int u){
  if ( T[u].p == NIL ) return NIL;
  if ( T[T[u].p].l != u && T[T[u].p].l != NIL ) return T[T[u].p].l;
  if ( T[T[u].p].r != u && T[T[u].p].r != NIL ) return T[T[u].p].r;
  return NIL;
}

void print(int u){
  printf("node %d: ", u);

  printf("parent = %d, ", T[u].p);
  printf("sibling = %d, ", getSibling(u));
  int deg = 0;
  if ( T[u].l != NIL ) deg++;
  if ( T[u].r != NIL ) deg++;
  printf("degree = %d, ", deg);
  printf("depth = %d, ", D[u]);
  printf("height = %d, ", H[u]);

  if ( T[u].p == NIL ){
    printf("root\n");
  } else if ( T[u].l == NIL && T[u].r == NIL ){
    printf("leaf\n");
  } else {
    printf("internal node\n");
  }
}


int main(){
  int i, v, l, r;
  scanf("%d", &n);

  for ( i = 0; i < n; i++ ) {
    T[i].p = NIL;
  }

  for ( i = 0; i < n; i++ ){
    scanf("%d %d %d", &v, &l, &r);
    T[v].l = l;
    T[v].r = r;
    if ( l != NIL ) T[l].p = v;
    if ( r != NIL ) T[r].p = v;
  }

  for ( i = 0; i < n; i++ ){
    D[i] = getDepth(i);
    H[i] = 0;
  }

  for ( i = 0; i < n; i++ ){
    if ( T[i].l == NIL && T[i].r == NIL ) { // is leaf
      H[i] = 0;
      int p = T[i].p;
      int c = 1;
      while(1){
	if ( p == NIL ) break;
	if ( H[p] < c ) H[p] = c;
	c++;
	p = T[p].p;
      }
    }
  }

  for ( i = 0; i < n; i++ ) print(i);
  return 0;
}
