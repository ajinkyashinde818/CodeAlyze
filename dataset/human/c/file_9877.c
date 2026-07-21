#include<stdio.h>
#define MAX 100005
#define NIL -1

struct Node{ int p, l, r;};
struct Node T[MAX];
int n, H, D[MAX];

void getDepth(int u){
  // if(D[u]!=NIL) return ;
 
  int d = 0;
  if(T[u].r!=NIL){
   
    D[T[u].r]=D[u];
    getDepth(T[u].r);
  }
  if(T[u].l!=NIL){ 
    D[T[u].l]=D[u]+1;
    getDepth(T[u].l);
  }
}

void print(int u){
  printf("node %d: parent = %d, depth = %d,",u,T[u].p,D[u]);
  if(T[u].p==NIL) printf(" root, ");
  else if(T[u].l==NIL) printf(" leaf, ");
  else printf(" internal node, ");
  printf("[");
  int a;
  a=u;
  if(T[a].l!=NIL){ 
    printf("%d",T[a].l);   
    if(T[T[a].l].r==NIL) printf("]\n");
    else printf(", ");
    a=T[a].l;
    while(T[a].r!=NIL){
      printf("%d",T[a].r);
      if(T[T[a].r].r==NIL) printf("]\n");
      else printf(", ");
      a=T[a].r;
    }
  }
  else puts("]");
 
}

main(){
  int i, j, d, v, c, l,r;

  scanf("%d", &n);

  for ( i = 0; i < n; i++ ) {
    T[i].p = T[i].l = T[i].r =D[i]= NIL;
  }

  for ( i = 0; i < n; i++ ){
    scanf("%d %d", &v, &d);
    for ( j = 0; j < d; j++ ){
      scanf("%d", &c);
      T[c].p=v;
      if(j>=1){T[r].r=c;}
      if(j==0){T[v].l=c;}
	r=c;
      }
  }
  

  for ( i = 0; i < n; i++ ){
    if(T[i].p==NIL){D[i]=0; getDepth(i); break;}
  }
  /*

    ...

   */

  for ( i = 0; i < n; i++ ) print(i);
  return 0;
}
