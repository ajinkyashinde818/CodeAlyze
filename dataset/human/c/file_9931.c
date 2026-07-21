#include <stdio.h>

#define Max 100000
#define NIL -1

int rec( int, int );
void print(int);

struct node{
  int p, l, r;
};

struct node T[Max];
int n, D[Max];

int main(){
  int i, j, v, c, l, r, d;
  scanf("%d",&n);
  for( i = 0 ; i < n ; i++)
    T[i].p = T[i].l = T[i].r =NIL;

  for( i = 0 ; i < n ; i++){
    scanf("%d%d",&v,&d);
    for( j = 0 ; j < d ; j++){
      scanf("%d",&c);
      if( j == 0) T[v].l = c;
      else  T[l].r = c;
      l = c;
      T[c].p = v;
    }
  }
  for( i = 0 ; i < n ; i++){
    if(T[i].p == NIL) 
      r = i;
  }
  rec(r,0);

  for( i = 0 ; i < n ; i++)
    print(i);

  return 0;
}

void print(int u){
  int i, c;
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].p);
  printf("depth = %d, ",D[u]);

  if( T[u].p == NIL ) printf("root, ");
  else if( T[u].l == NIL ) printf("leaf, ");
  else printf("internal node, ");

  printf("[");

  for( i = 0 , c = T[u].l ; c != NIL ; i++, c =T[c].r){
    if(i != 0 ) printf(", ");
    printf("%d",c);
  }
  printf("]\n");
}

int rec(int u, int p) {
  D[u] = p;
  if( T[u].r != NIL ) rec(T[u].r ,p);
  if( T[u].l != NIL ) rec(T[u].l ,p+1);
}
