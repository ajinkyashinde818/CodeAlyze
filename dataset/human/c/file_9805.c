#include<stdio.h>
#define MAX 100005
#define NIL -1
  
struct Node{ int p, l, r;};
struct Node T[MAX];
int n, H, D[MAX];
int getDepth(int);
void print(int);


  
int main(){
  int i, j, d, v, c,l,r;
    
  scanf("%d",&n);
    
  for ( i = 0; i < n; i++ ) {
    T[i].p = T[i].l = T[i].r = NIL;
  }
    
  for ( i = 0; i < n; i++ ){
    scanf("%d %d", &v, &d);
    for ( j = 0; j < d; j++ ){
      scanf("%d", &c);
      T[c].p = v;
        
      if(j == 0) T[v].l = c;
        
      else if (j >= 1)
	T[r].r = c;
      r = c;
    }
  }
    
  
  for ( i = 0; i < n; i++ ){
    D[i] = getDepth(i);
  }
  
  for ( i = 0; i < n; i++ ) print(i);
  return 0;
}


int getDepth(int u){
  int d = 0;
  
  while(T[u].p >= 0){
    u = T[u].p; 
    d++;
  }
  
  return d;
}
  
void print(int u){
  if(T[u].p == NIL)
    printf("node %d: parent = %d, depth = %d, root, ",u,T[u].p,D[u]);
    
  else if(T[u].l == NIL)
    printf("node %d: parent = %d, depth = %d, leaf, ",u,T[u].p,D[u]);
    
    
  else printf("node %d: parent = %d, depth = %d, internal node, ",u,T[u].p,D[u]);
    
    
  printf("[");
  int t; 
  t = u;
  if(T[t].l  != NIL){
    printf("%d",T[t].l);
    if(T[T[t].l].r == NIL)
      printf("]\n");
    else printf(",");
    t =T[t].l;
    while(T[t].r != NIL){
      printf(" %d",T[t].r);
  
      if(T[T[t].r].r == NIL)
	printf("]\n");
      else printf(",");
      t =T[t].r;
    }
  }
  else  printf("]\n");
}
