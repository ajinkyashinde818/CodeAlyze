#include <stdio.h>
#define MAX 100000
#define NIL -1

typedef struct{
  int p,l,r;
}Node;

void setdepth(int, int);
int setheight(int);
void print(int);
int getsibling(int);

Node T[MAX];
int n,D[MAX],H[MAX];

int main(){
  int v,l,r,i,root=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    T[i].p=NIL;
  }
  
  for(i=0;i<n;i++){
    scanf("%d%d%d",&v,&l,&r);
    T[v].l=l;
    T[v].r=r;
    if(l!=NIL)
      T[l].p=v;
    if(r!=NIL)
      T[r].p=v;
  }
  
  for(i=0;i<n;i++){
    if(T[i].p==NIL)
      root=i;
  }
  
  setdepth(root,0);
  setheight(root);
  
  for(i=0;i<n;i++)
    print(i);

  return 0;
}

void setdepth(int u, int d){
  if(u==NIL)
    return;
  D[u]=d;
  setdepth(T[u].l,d+1);
  setdepth(T[u].r,d+1);
}

int setheight(int u){
  int h1=0,h2=0;

  if(T[u].l!=NIL)
    h1=setheight(T[u].l)+1;
  if(T[u].r!=NIL)
    h2=setheight(T[u].r)+1;
  
  if(h1>h2)
    return H[u]=h1;
  else
    return H[u]=h2;
}

void print(int u){
  int deg=0;

  printf("node %d: ",u);
  printf("parent = %d, ",T[u].p);
  printf("sibling = %d, ",getsibling(u));

  if(T[u].l!=NIL)
    deg++;
  if(T[u].r!=NIL)
    deg++;

  printf("degree = %d, ",deg);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",H[u]);

  if(T[u].p==NIL)
    printf("root\n");
  else if(T[u].l==NIL && T[u].r==NIL)
    printf("leaf\n");
  else
    printf("internal node\n");
}

int getsibling(int u){
  if(T[u].p==NIL)
    return NIL;
  if(T[T[u].p].l!=u && T[T[u].p].l!=NIL)
    return T[T[u].p].l;
  if(T[T[u].p].r!=u && T[T[u].p].r!=NIL)
    return T[T[u].p].r;
  return NIL;
}
