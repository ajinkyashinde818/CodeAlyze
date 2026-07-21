#include<stdio.h>
#define MAX 999999
#define NIL -1

struct Node{
  int p, l, r;
};

struct Node T[MAX];

/* プロトタイプ宣言 */
int getSib(int u);
void doPrint (int u);
int getDepth(int u);

int n, D[MAX], H[MAX];

int getSib(int u){
  if ( T[u].p == NIL ) return NIL;
  if ( T[T[u].p].r != u && T[T[u].p].r != NIL ) return T[T[u].p].r;
  if ( T[T[u].p].l != u && T[T[u].p].l != NIL ) return T[T[u].p].l;
  
  return NIL;
}

int getDepth(int u){
  int dep = 0;
  while(1){
    u = T[u].p;
    if ( u == NIL ) break;
    dep++;
  }
  return dep;
}


void doPrint(int u){
	int d = 0;
  printf("node %d: ", u);

  printf("parent = %d, ", T[u].p);
  printf("sibling = %d, ", getSib(u));

  if ( T[u].l != NIL ) d++;
  if ( T[u].r != NIL ) d++;
  printf("degree = %d, ", d);
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
  	H[i] = 0;
    D[i] = getDepth(i);
  }

  for ( i = 0; i < n; i++ ){
    if ( T[i].l == NIL && T[i].r == NIL ) {
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

  for ( i = 0; i < n; i++ ) doPrint(i);
  return 0;
}
