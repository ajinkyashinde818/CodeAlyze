#include <stdio.h>
#define N 10000
#define NIL -1

typedef struct{
  int p;
  int L;
  int R;
}node;

node T[N];
int n, D[N],H[N];

int depth(int,int);
int height(int);
int sibling(int);

int main(){
  int i,j,v,l,r,root = 0;
  int deg = 0;
  scanf("%d",&n);

  for(i = 0; i < n; i++)
    T[i].p = NIL;

  for(i = 0; i < n; i++){
    scanf("%d%d%d",&v,&l,&r);
    T[v].L = l;
    T[v].R = r;
    if(l != NIL) T[l].p = v;
    if(r != NIL) T[r].p = v;
  }
  for(i = 0; i < n; i++){
    if(T[i].p == NIL) root = i;
  }
  
  depth(root,0);
  height(root);

  for(i = 0; i < n; i++){
    printf("node %d: parent = %d, sibling = %d, ",i,T[i].p,sibling(i));
    deg = 0;
    if(T[i].L != NIL) deg++;
    if(T[i].R != NIL) deg++;
    
    printf("degree = %d, depth = %d, height = %d, ",deg,D[i],H[i]);

    if(T[i].p == NIL){
      printf("root\n");
    }
    else if(T[i].L == NIL && T[i].R == NIL){
      printf("leaf\n");
    }
    else{
      printf("internal node\n");
    }
     }

 
  return 0;
}

int depth(int u,int d){
  if(u == NIL) return 0;
  D[u] = d;
  depth(T[u].L,d+1);
  depth(T[u].R,d+1);
}

int height(int u){
  int h1 = 0,h2 = 0;
  if(T[u].L != NIL) h1 = height(T[u].L) + 1;
  if(T[u].R != NIL) h2 = height(T[u].R) + 1;
  return H[u] = (h1 > h2 ? h1 : h2);
}

int sibling(int u){
  if(T[u].p == NIL) return NIL;
  if(T[T[u].p].L != NIL &&T[T[u].p].L != u) return T[T[u].p].L;
  if(T[T[u].p].R != NIL &&T[T[u].p].R != u) return T[T[u].p].R;
  return NIL;
}
