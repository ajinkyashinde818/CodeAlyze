#include<stdio.h>
#define NIL -1
#define MAX 10010
struct Node{int p, l, r;
};
struct Node T[MAX];
int n,D[MAX], H[MAX];
int wowDep(int);
int wowSib(int);
void print(int);
int main(){
  int i, v, l, r,n,m;
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
    D[i] = wowDep(i);
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
int wowDep(int a){
  int depth = 0;
  while(1){
    a = T[a].p;
    if ( a == NIL ) break;
    depth++;
  }
  return depth;
}
int wowSib(int a){
  if ( T[a].p == NIL ) return NIL;
  if ( T[T[a].p].l != a && T[T[a].p].l != NIL ) return T[T[a].p].l;
  if ( T[T[a].p].r != a && T[T[a].p].r != NIL ) return T[T[a].p].r;
  return NIL;
}
void print(int a){
      int d;
    d=0;
    printf("node %d: ", a);
  printf("parent = %d, ", T[a].p);
  printf("sibling = %d, ", wowSib(a));

  if ( T[a].l != NIL ) d++;
  if ( T[a].r != NIL ) d++;
  printf("degree = %d, ", d);
  printf("depth = %d, ", D[a]);
  printf("height = %d, ", H[a]);

  if ( T[a].p == NIL ){
    printf("root\n");
  } else if ( T[a].l == NIL && T[a].r == NIL ){
    printf("leaf\n");
  } else {
    printf("internal node\n");
  }
}
