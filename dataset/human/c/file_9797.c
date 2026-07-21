#include <stdio.h>
#define MAX 100005
#define NIL -1
void setDepth(int, int);
void print(int);

struct Node{
  int p;
  int l;
  int r;
};

struct Node T[MAX];
int D[MAX];


int main(){
  int n, i, id, k, j, c, x, r;
  scanf("%d",&n);
  
  for(i=0; i<n; i++){
    T[i].p=NIL;
    T[i].l=NIL;
    T[i].r=NIL;
  }

  for(i=0; i<n; i++){
    scanf("%d%d",&id, &k);

    for(j=0; j<k; j++){
        scanf("%d",&c);
        if(j == 0) T[id].l=c;
        else T[x].r=c;
        x=c;
        T[c].p=id;
    }
  }

  for(i=0; i<n; i++){
    if(T[i].p == NIL) r=i;
  }

  setDepth(r, 0);

  for(i=0; i<n; i++) print(i);

  return 0;
}

void setDepth(int u, int d){
  D[u] = d;
  if(T[u].r != NIL) setDepth(T[u].r, d);
  if(T[u].l != NIL) setDepth(T[u].l, d+1);
}

void print(int u){
  int i;

  printf("node %d: parent = %d, depth = %d, ",u,T[u].p,D[u]);
  
  if(T[u].p == NIL) printf("root, ");
  else if(T[u].l == NIL) printf("leaf, ");
  else printf("internal node, ");
  
  printf("[");

  if(T[u].l == NIL) printf("]\n");
  
  else {
    for(i = T[u].l; T[i].r != NIL; i = T[i].r) printf("%d, ",i);
    printf("%d]\n",i);
  }
}
