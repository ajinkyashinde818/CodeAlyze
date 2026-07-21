#include<stdio.h>

#define MAX 100000
#define NIL -1
 
struct node{ 
  int p, l, r;
};
struct node T[MAX];

void depth(int);
void print(int);

int n, H, D[MAX];

int main()
{
  int i, j, d, v, c, l, r;
 
  scanf("%d", &n);
 
  for ( i = 0; i < n; i++ ) {
    T[i].p = NIL;
    T[i].l = NIL;
    T[i].r = NIL;
  }
 
  for ( i = 0; i < n; i++ ){
    scanf("%d %d", &v, &d);
    for ( j = 0; j < d; j++ ){
      scanf("%d", &c);
      T[c].p = v;
      if(j >= 1)
	T[r].r = c;
      if(j == 0)
	T[v].l = c;
      r = c;
      }
  }
   
 
  for ( i = 0; i < n; i++ ){
    if(T[i].p == NIL) {
      D[i] = 0; 
      depth(i); 
      break;
    }
  }
 
  for ( i = 0; i < n; i++ ) {
    print(i);
  }
  return 0;
}

void depth(int u)
{
  int d = 0;

  if(T[u].r != NIL){   
    D[T[u].r] = D[u];
    depth(T[u].r);
  }
  if(T[u].l != NIL){ 
    D[T[u].l] = D[u]+1;
    depth(T[u].l);
  }
}
 
void print(int u)
{
  int a;

  printf("node %d: parent = %d, depth = %d,", u, T[u].p, D[u]);
  if(T[u].p == NIL)
    printf(" root, ");
  else if(T[u].l == NIL) 
    printf(" leaf, ");
  else 
    printf(" internal node, ");
  printf("[");
  a = u;
  if(T[a].l != NIL) { 
    printf("%d", T[a].l);   
    if(T[T[a].l].r == NIL) 
      printf("]\n");
    else 
      printf(", ");
    a = T[a].l;
    while(T[a].r != NIL){
      printf("%d", T[a].r);
      if(T[T[a].r].r == NIL) 
	printf("]\n");
      else 
	printf(", ");
      a = T[a].r;
    }
  }
  else
    printf("]\n"); 
}
