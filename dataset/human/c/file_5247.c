#include<stdio.h>
#define MAX 10000
#define NIL -1

struct Node{
  int pa, le, ri;
};

struct Node T[MAX];
int n;
int D[MAX], H[MAX];

int getDepth(int u);
int getSibling(int u);
void print(int u);

int main(){
  int i, v, l, r;
  
  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) {
    T[i].pa = NIL;
  }
  for ( i = 0; i < n; i++ ){
    scanf("%d %d %d", &v, &l, &r);
    T[v].le = l;
    T[v].ri = r;
    if ( l != NIL ) T[l].pa = v;
    if ( r != NIL ) T[r].pa = v;
  }
  for ( i = 0; i < n; i++ ){
    D[i] = getDepth(i);
    H[i] = 0;
  }
  for ( i = 0; i < n; i++ ){
    if ( T[i].le == NIL && T[i].ri == NIL ) { // is leaf
      H[i] = 0;
      int p = T[i].pa;
      int c = 1;
      while(1){
	if ( p == NIL ) break;
	if ( H[p] < c ) H[p] = c;
	c++;
	p = T[p].pa;
      }
    }
  }
  for ( i = 0; i < n; i++ ) print(i);
  return 0;
}

int getDepth(int u){
  int d = 0;
  while(1){
    u = T[u].pa;
    if ( u == NIL ) break;
    d++;
  }
  return d;
}

int getSibling(int u){
  if ( T[u].pa == NIL ) return NIL;
  if ( T[T[u].pa].le != u && T[T[u].pa].le != NIL ) return T[T[u].pa].le;
  if ( T[T[u].pa].ri != u && T[T[u].pa].ri != NIL ) return T[T[u].pa].ri;
  return NIL;
}

void print(int u){
  printf("node %d: ", u);

  printf("parent = %d, ", T[u].pa);
  printf("sibling = %d, ", getSibling(u));
  int deg = 0;
  if ( T[u].le != NIL ) deg++;
  if ( T[u].ri != NIL ) deg++;
  printf("degree = %d, ", deg);
  printf("depth = %d, ", D[u]);
  printf("height = %d, ", H[u]);

  if ( T[u].pa == NIL ){
    printf("root\n");
  } else if ( T[u].le == NIL && T[u].ri == NIL ){
    printf("leaf\n");
  } else {
    printf("internal node\n");
  }
}
