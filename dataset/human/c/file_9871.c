#include<stdio.h>

#define MAX 100005
#define NIL -1

struct Node{
  int p;
  int l;
  int r;
};

struct Node N[MAX];

int n, H, D[MAX];

int getDepth(int u){
  int d = 0;
  
  while(N[u].p >= 0){
    u = N[u].p;
    d++;
  }
  
  return d;
}

void printTree(int u){
  int t;

  if(N[u].p == NIL) printf("node %d: parent = %d, depth = %d, root, ", u, N[u].p, D[u]);
  
  else if(N[u].l == NIL) printf("node %d: parent = %d, depth = %d, leaf, ", u, N[u].p, D[u]);
  
  else printf("node %d: parent = %d, depth = %d, internal node, ", u, N[u].p, D[u]);
    
  printf("[");

  t = u;

  if(N[t].l != NIL){
    printf("%d", N[t].l);

    if(N[N[t].l].r == NIL) printf("]\n");

    else printf(",");

    t = N[t].l;

    while(N[t].r != NIL){
      printf(" %d",N[t].r);
      
      if(N[N[t].r].r == NIL) printf("]\n");

      else printf(",");

      t = N[t].r;
    }
  }
  
  else printf("]\n");
}

int main(){
  int i, j, d, v, c, l, r;
  
  scanf("%d", &n);
  
  for(i = 0; i < n; i++){
    N[i].p = N[i].l = N[i].r = NIL;
  }
  
  for ( i = 0; i < n; i++ ){
    scanf("%d %d", &v, &d);

    for(j = 0; j < d; j++){
      scanf("%d", &c);

      N[c].p = v;
      
      if(j == 0) N[v].l = c;
      
      else if (j >= 1) N[r].r = c;
      r = c;
    }
  }
  
  for(i = 0; i < n; i++) D[i] = getDepth(i);
  
  for(i = 0; i < n; i++) printTree(i);
  return 0;
}
