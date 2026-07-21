#include <stdio.h>
#include <stdlib.h>
#define N 10000
#define NIL -1
typedef struct node{
  int parent;
  int right;
  int left;
}Node;

Node T[N];
int n,D[N],H[N];
void setDepth(int,int);
void print(int);
int setHeight(int);
int getSibling(int);

int main(){
  int i,v,l,r,root=0;
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    T[i].parent = NIL;
  }
  
  for(i=0;i<n;i++){
    scanf("%d%d%d",&v,&l,&r);
    T[v].left = l;
    T[v].right = r;
    if(l!=NIL) T[l].parent = v;
    if(r!=NIL) T[r].parent = v;
  }
  for(i=0;i<n;i++){
    if(T[i].parent == NIL){
      root=i;
    }
  }
  setDepth(root,0);
  setHeight(root);
  
  for(i=0;i<n;i++){
    print(i);
  }

  return 0;
}

void setDepth(int u,int d){
  if(u==NIL){
    return;
  }
  D[u]=d;
  setDepth(T[u].left,d+1);
  setDepth(T[u].right,d+1);
}

int setHeight(int u){
  int h1=0,h2=0;
  if(T[u].left != NIL){
    h1 = setHeight(T[u].left)+1;
  }
  if(T[u].right != NIL){
    h2 = setHeight(T[u].right)+1;
  }
  return H[u] = (h1 > h2 ? h1 : h2);
}

int getSibling(int u){
  if(T[u].parent == NIL) return NIL;
  if(T[T[u].parent].left != u && T[T[u].parent].left != NIL){
    return T[T[u].parent].left;
  }
  if(T[T[u].parent].right != u && T[T[u].parent].right != NIL){
    return T[T[u].parent].right;
  }
  return NIL;
}
void print(int a){
  int deg=0;
  printf("node %d: ",a);
  printf("parent = %d, ",T[a].parent);
  printf("sibling = %d, ",getSibling(a));
  if(T[a].left != NIL) deg++;
  if(T[a].right != NIL) deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",D[a]);
  printf("height = %d, ",H[a]);

  if(T[a].parent== NIL){
    printf("root\n");
  }
  else if(T[a].left == NIL && T[a].right == NIL){
    printf("leaf\n");
  }
  else printf("internal node\n");
}
