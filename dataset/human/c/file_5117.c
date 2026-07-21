#include<stdio.h>

#define NIL -1
#define MAX 100000

typedef struct Node{
  int parent,lf,rg;
}node;

node ttt[MAX];

int k, ddd[MAX], hhh[MAX];

void Dep(int u, int p){
  if(u==NIL) return;
  ddd[u]=p;
  Dep(ttt[u].lf,p+1);
  Dep(ttt[u].rg,p+1);
}

int Height(int u){
  int p1=0,p2=0;
  if(ttt[u].lf !=NIL){
    p1=Height(ttt[u].lf)+1;
  }
  if(ttt[u].rg !=NIL){
    p2=Height(ttt[u].rg)+1;
  }

  if(p1<p2)hhh[u]=p2;
  else hhh[u]=p1;
  return hhh[u];
}

int Sibling(int u){
  if(ttt[u].parent==NIL)return NIL;
  if(ttt[ttt[u].parent].lf!=u && ttt[ttt[u].parent].lf!=NIL)
    return ttt[ttt[u].parent].lf;
  if(ttt[ttt[u].parent].rg!=u && ttt[ttt[u].parent].rg!=NIL)
    return ttt[ttt[u].parent].rg;
  return NIL;
}

void Prin(int u){
  int count=0;
  printf("node %d: ", u);
  printf("parent = %d, ", ttt[u].parent);
  printf("sibling = %d, ", Sibling(u));
  if(ttt[u].lf!=NIL)count++;
  if(ttt[u].rg!=NIL)count++;
  printf("degree = %d, ", count);
  printf("depth = %d, ", ddd[u]);
  printf("height = %d, ", hhh[u]);
  if(ttt[u].parent==NIL){
    printf("root\n");
  }else if(ttt[u].lf==NIL && ttt[u].rg==NIL){
    printf("leaf\n");
  }else {
    printf("internal node\n");
  }
}

int main(){
  int v, l, r, root=0, i,n;
  scanf("%d", &n);
  for(i=0 ; i<n ; i++)ttt[i].parent=NIL;
  for(i=0 ; i<n ; i++){
    scanf("%d%d%d",&v, &l, &r);
    ttt[v].lf=l;
    ttt[v].rg=r;
    if(l!=NIL)ttt[l].parent=v;
    if(r!=NIL)ttt[r].parent=v;
  }
  for(i=0 ; i<n ; i++) if(ttt[i].parent==NIL) root=i;
  Dep(root, 0);
  Height(root);
  for(i=0 ; i<n ; i++)Prin(i);
  return 0;
}
