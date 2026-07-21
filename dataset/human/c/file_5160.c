#include <stdio.h>
#define NIL -1
#define MAX 100005

typedef struct node{
  int p,l,r;
}Node;
Node T[MAX];
int D[MAX],H[MAX];
int n;

void depth(int,int);
int height(int);
int sibling(int);

void print(int);

int main(){
  int i,j,v,l,r,root=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)T[i].p=NIL;

  for(i=0;i<n;i++){
    scanf("%d%d%d",&v,&l,&r);
    T[v].l=l;
    T[v].r=r;
    if(l!=NIL)T[l].p=v;
    if(r!=NIL)T[r].p=v;
}
  for(i=0;i<n;i++){
    if(T[i].p==NIL)root=i;
}
  depth(root,0);
  height(root);
  for(i=0;i<n;i++)print(i);
  return 0;
}

void depth(int u,int d){
  if(u==NIL)return ;//                                                                             
  D[u]=d;
  depth(T[u].l,d+1);
  depth(T[u].r,d+1);
}
int height(int u){
  int h1=0,h2=0;
  if(T[u].l!=NIL)h1=height(T[u].l)+1;
  if(T[u].r!=NIL)h2=height(T[u].r)+1;
  return H[u]=(h1>h2 ? h1:h2);//                                                                   
}

int sibling(int u){
  if(T[u].p==NIL)return NIL;
  if(T[T[u].p].l!=u && T[T[u].p].l!=NIL)return T[T[u].p].l;
  if(T[T[u].p].r!=u && T[T[u].p].r !=NIL)return T[T[u].p].r;
  return NIL;
}

void print(int u){
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].p);
  printf("sibling = %d, ",sibling(u));
  int deg = 0;
  if(T[u].l!=NIL)deg++;
  if(T[u].r!=NIL)deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",H[u]);

  if(T[u].p==NIL){
    printf("root\n");
  }else if(T[u].l==NIL && T[u].r==NIL){
    printf("leaf\n");
  }else {
    printf("internal node\n");
}


}
