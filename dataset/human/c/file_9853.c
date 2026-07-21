#include<stdio.h>
#define MAX 100005
#define NIL -1

struct Node{ int p, l, r;};
struct Node T[MAX];
int n, H, D[MAX];

int getDepth(int u){
  int d = 0;
  int i = 0;
  while(1){
    if(T[u].p == NIL) break;
    d++;
    u = T[u].p;
  }
  return d;
}

void print(int u){
  int a;
  
  printf("node %d: parent = %d, depth = %d, ",u,T[u].p,D[u]);
  
  if( T[u].p == NIL) printf("root, [");
  else if(T[u].l == NIL) printf("leaf, [");
  else printf("internal node, [");
  
  a = T[u].l;
  if( a != NIL){
    while(1){
      if(T[a].r == NIL){
	printf("%d",a);
	break;
      }
      else {
	printf("%d, ",a);
	a = T[a].r;
      }
    }
  }

    printf("]\n");
}

main(){
  int i, j, d, v, c, l;
  int pre;
  scanf("%d", &n);
  
  for ( i = 0; i < n; i++ ) {
    T[i].p = T[i].l = T[i].r = NIL;
  }
  
  for ( i = 0; i < n; i++ ){
    scanf("%d %d", &v, &d);
    for ( j = 0; j < d; j++ ){
      scanf("%d", &c);
      
      if(j == 0){
	T[v].l = c;
	T[c].p = v;
	pre = c; 
      }
      else if(j != 0){
	T[pre].r = c;
	T[c].p = v;
	pre = c;
      }
    }
  }
  
  for ( i = 0; i < n; i++ ){
    D[i] = getDepth(i);
  }

  for ( i = 0; i < n; i++ ) print(i);
  return 0;
}
