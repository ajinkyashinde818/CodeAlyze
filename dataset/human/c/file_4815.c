#include<stdio.h>

#define N 10000
#define NIL -1

struct Node{
  int parent,left,right;
};

struct Node T[N];
int n,Dep[N],Hei[N];

void Depth(int u,int d){
  
  if(u==NIL) return;
  
  Dep[u]=d;
  Depth(T[u].left,d+1);
  Depth(T[u].right,d+1);
}

int Height(int u){
  int h1=0,h2=0;

  if(T[u].left!=NIL) h1=Height(T[u].left)+1;
  if(T[u].right!=NIL) h2=Height(T[u].right)+1;

  if(h1>h2) return Hei[u]=h1;
  else return Hei[u]=h2;
}

int Sibling(int u){

  if(T[u].parent==NIL) return NIL;

  if(T[T[u].parent].left!=u && T[T[u].parent].left!=NIL){
    return T[T[u].parent].left;
  }

  if(T[T[u].parent].right!=u && T[T[u].parent].right!=NIL){
    return T[T[u].parent].right;
  }

  return NIL;
}

void print(int u){
  int count=0;
  
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].parent);
  printf("sibling = %d, ",Sibling(u));

  if(T[u].left!=NIL) count++;
  if(T[u].right!=NIL) count++;

  printf("degree = %d, ",count);
  printf("depth = %d, ",Dep[u]);
  printf("height = %d, ",Hei[u]);

  if(T[u].parent==NIL) printf("root\n");
  else if(T[u].left==NIL && T[u].right==NIL) printf("leaf\n");
  else printf("internal node\n");
}

int main(){
  int i,v,l,r,root=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    T[i].parent=NIL;
  }

  for(i=0;i<n;i++){
    scanf("%d %d %d",&v,&l,&r);

    T[v].left=l;
    T[v].right=r;

    if(l!=NIL) T[l].parent=v;
    if(r!=NIL) T[r].parent=v;
  }

  for(i=0;i<n;i++){
    if(T[i].parent==NIL) root=i;
  }

  Depth(root,0);
  Height(root);

  for(i=0;i<n;i++){
    print(i);
  }

  return 0;
}
