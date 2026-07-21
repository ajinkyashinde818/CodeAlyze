/*
#include <stdio.h>
#define N -1;

typedef struct{
  int id;
  int left;
  int right;
}t;

typedef struct{
  int id;
  int pid;
  int sb;
  int d;
  int h;
  int cc;
}T;

int main()
{
  int n,i,a,*p;
  T Tree[25];
  t tree[25];
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    Tree[i].id = -1;
    Tree[i].pid = -1;
    Tree[i].sb = -1;
    Tree[i].d = -1;
    Tree[i].h = -1;
    Tree[i].cc = -1;
  }

  for(i=0;i<n;i++){
    scanf("%d",&a);
    tree[a].id = a;
    scanf("%d%d",&tree[a].left,&tree[a].right);
  }

  for(i=0;i<n;i++){
    if(tree[i].left!=-1 && tree[i].right==-1){
      Tree[tree[i].left].pid = tree[i].id;
      Tree[i].cc = 1;
    }
    else if(tree[i].right!=-1 && tree[i].left==-1){
      Tree[tree[i].right].pid = tree[i].id;
      Tree[i].cc = 1;
    }
    else if(tree[i].left!=-1 && tree[i].right!=-1){
      Tree[tree[i].left].pid = tree[i].id;
      Tree[tree[i].right].pid = tree[i].id;
      Tree[i].cc = 2;
      Tree[tree[i].left].sb = tree[i].right;
      Tree[tree[i].right].sb = tree[i].left;
    }
    else Tree[i].cc = 0;
  }

  for(i=0;i<n;i++){
    if(Tree[i].pid==-1){
      Tree[i].d = 0;
      p = &Tree[i];
    }
  }
*/
  
#include<stdio.h>
#define NIL -1

typedef struct node{
  int pa;
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
  if(T[u].pa == NIL)return NIL;
  if(T[T[u].pa].l != u && T[T[u].pa].l != NIL)return T[T[u].pa].l;
  if(T[T[u].pa].r != u && T[T[u].pa].r != NIL)return T[T[u].pa].r;
  return NIL;
}

int main(){
  int n,i,j,v,l,r,root,deg;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    T[i].pa = NIL;
  }  

  for(i=0;i<n;i++){
    scanf("%d%d%d",&v,&l,&r);
    T[v].l = l;
    T[v].r = r;
    if(l != NIL)T[l].pa = v;
    if(r != NIL)T[r].pa = v;
  }

  for(i=0;i<n;i++){
    if(T[i].pa == NIL ){
      root = i;
    }
  }
  setDepth(root,0);
  setHeight(root);

  for(i=0;i<n;i++){
    deg = 0;
    printf("node %d: parent = %d, sibling = %d, ",i,T[i].pa,getSibling(i));
    if(T[i].l != NIL)deg++;
    if(T[i].r != NIL)deg++;
    printf("degree = %d, depth = %d, height = %d, ",deg,T[i].d,T[i].h);
    if(T[i].pa == NIL)printf("root\n");
    else if(T[i].l == NIL && T[i].r == NIL)printf("leaf\n");
    else printf("internal node\n");
  }
  return 0;
}
