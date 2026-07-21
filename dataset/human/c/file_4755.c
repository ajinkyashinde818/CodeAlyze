#include <stdio.h>
#define NIL -1
#define MAX 10000

struct Node {int p,l,r; };

void setDepth(int ,int);
int setheight(int);
int max(int,int);
int getsibling(int);
void print(int);

struct Node T[MAX];
int H[MAX],D[MAX],n;

int main(){
  int i,v,l,r,root=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    T[i].p=NIL;
  for(i=0;i<n;i++){
    scanf("%d%d%d",&v,&l,&r);
    T[v].l=l;
    T[v].r=r;
    if(l!=NIL)T[l].p=v;
    if(r!=NIL)T[r].p=v;
  }
  for(i=0;i<n;i++)
    if(T[i].p==NIL)root=i;
  setDepth(root ,0);
  setheight(root);
  
  for(i=0;i<n;i++)
    print(i);
  
  return 0;
}

int setheight(int u){
  int h1=0,h2=0;
  if(T[u].r !=NIL)
    h1=setheight(T[u].r)+1;
  if(T[u].l!=NIL)
    h2=setheight(T[u].l)+1;

  return H[u]=max(h1,h2);
}
int max(int h1,int h2){
  if(h1>h2)return h1;
  else return h2;
}

void setDepth(int u, int p){
  D[u]=p; // Depth Array
  if(T[u].r != NIL)setDepth(T[u].r,p+1);
  if(T[u].l != NIL)setDepth(T[u].l,p+1);
}

int getsibling(int u){
  if(T[u].p==NIL)
    return NIL;
  if(T[T[u].p].l!= u&&T[T[u].p].l!=NIL)
    return T[T[u].p].l;
  if(T[T[u].p].r!= u&&T[T[u].p].r!=NIL)
    return T[T[u].p].r;
  return NIL;
}

void print(int u){
  int deg=0;
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].p);
  printf("sibling = %d, ",getsibling(u));
  if(T[u].l!=NIL)deg++;
  if(T[u].r!=NIL)deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",H[u]);

  if(T[u].p == NIL)
    printf("root\n");
  else if(T[u].l==NIL && T[u].r==NIL)
    printf("leaf\n");
  else printf("internal node\n");
}
