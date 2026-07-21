#include<stdio.h>
#define NIL -1

typedef struct node{
  int p;
  int l;
  int r;
  int d;
  int h;
}Node;

Node T[30];


void setDepth(int u,int d){
  if(u == NIL){
    return;
  }

  T[u].d = d;
  setDepth(T[u].l,d+1);
  setDepth(T[u].r,d+1);
}

int setHeight(int u){
  int h1 = 0;
  int h2 = 0;

  if(T[u].l != NIL){
    h1 = setHeight(T[u].l)+1;
  }
  if(T[u].r != NIL){
    h2 = setHeight(T[u].r)+1;
  }
  return T[u].h = (h1 > h2 ? h1 : h2);
}

int getSibling(int u){
  if(T[u].p == NIL)return NIL;
  if(T[T[u].p].l != u && T[T[u].p].l != NIL)return T[T[u].p].l;
  if(T[T[u].p].r != u && T[T[u].p].r != NIL)return T[T[u].p].r;
  return NIL;
}

int main(){
  int n,i,j,v,l,r,root,deg;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    T[i].p = NIL;
  }

  for(i=0;i<n;i++){
    scanf("%d%d%d",&v,&l,&r);
    T[v].l = l;
    T[v].r = r;
    if(l != NIL)T[l].p = v;
    if(r != NIL)T[r].p = v;
  }

  for(i=0;i<n;i++){
    if(T[i].p == NIL ){
      root = i;
    }
  }
  setDepth(root,0);
  setHeight(root);

  for(i=0;i<n;i++){
    deg = 0;
    printf("node %d: parent = %d, sibling = %d, ",i,T[i].p,getSibling(i));
    if(T[i].l != NIL)deg++;
    if(T[i].r != NIL)deg++;
    printf("degree = %d, depth = %d, height = %d, ",deg,T[i].d,T[i].h);
    if(T[i].p == NIL)printf("root\n");
    else if(T[i].l == NIL && T[i].r == NIL)printf("leaf\n");
    else printf("internal node\n");
  }
  return 0;
}
