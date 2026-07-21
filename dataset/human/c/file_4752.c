#include<stdio.h>

#define MAX 10000
#define NIL -1

typedef struct{
  int p,l,r;
}Node;

Node T[MAX];
int n,D[MAX],H[MAX];

void setDepth(int,int);
int setHeight(int);
int getSibling(int);
void print(int);

int main(){
  int i,v,l,r,root = 0;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    T[i].p = NIL;

  for(i=0;i<n;i++){
    scanf("%d %d %d",&v,&l,&r);
    T[v].l = l;
    T[v].r = r;
    if(l != NIL)T[l].p = v;
    if(r != NIL)T[r].p = v;
  }

  for(i=0;i<n;i++)
    if(T[i].p == NIL)root = i;

  setDepth(root,0);
  setHeight(root);

  for(i=0;i<n;i++)
    print(i);

  return 0;
}

void setDepth(int u, int d){

  if(u == NIL)return;
  D[u] = d;
  setDepth(T[u].l,d+1);
  setDepth(T[u].r,d+1);
}

int setHeight(int u){
  int h1,h2;

  h1 = h2 = 0;
  if(T[u].l != NIL)h1 = setHeight(T[u].l) + 1;
  if(T[u].r != NIL)h2 = setHeight(T[u].r) + 1;
  return H[u] = (h1 > h2 ? h1 : h2); 
}

int getSibling(int u){

  if(T[u].p == NIL)return NIL;
  if(T[T[u].p].l != u && T[T[u].p].l != NIL)
    return T[T[u].p].l;
  if(T[T[u].p].r != u && T[T[u].p].r != NIL)
    return T[T[u].p].r;
  return NIL;
}

void print(int u){
  int deg;

  printf("node %d: parent = %d, sibling = %d, ",u,T[u].p,getSibling(u));

  deg = 0;

  if(T[u].l != NIL)deg++;
  if(T[u].r != NIL)deg++;

  printf("degree = %d, depth = %d, height = %d, ",deg,D[u],H[u]);

  if(T[u].p == NIL)printf("root\n");
  else if(T[u].l == NIL && T[u].r == NIL)printf("leaf\n");
  else printf("internal node\n");
}
