#include<stdio.h>


#define MAX 1000
#define default -1
 
typedef struct node{
  int parent,left,right;
}Node;
 
Node T[MAX];
int n, D[MAX], H[MAX];

void setDepth(int, int);
int setHeight(int );
int getSibling(int );

int main(){
  int i,v,l,r,deg,root=0;
  scanf("%d",&n);
 
  for(i=0;i<n;i++){
    T[i].parent =default;

  }
  for(i=0;i<n;i++){
    scanf("%d%d%d",&v,&l,&r);
    T[v].left = l;
    T[v].right = r;
    if(l != default)T[l].parent = v;
    if(r != default)T[r].parent = v;
  }
 
  for(i=0; i<n; i++){
    if(T[i].parent == default) root = i;
  }
  setDepth(root, 0);
  setHeight(root);
 
  for(i = 0; i<n; i++){
    printf("node %d: ", i);
    printf("parent = %d, ", T[i].parent);
    printf("sibling = %d, ", getSibling(i));
    deg = 0;
    if(T[i].left != default) deg++;
    if(T[i].right != default) deg++;
    printf("degree = %d, ",deg);
    printf("depth = %d, ", D[i]);
    printf("height = %d, ", H[i]);
 
    if(T[i].parent == default){
      printf("root\n");
    } else if(T[i].left == default && T[i].right == default){
      printf("leaf\n");
    } else {
      printf("internal node\n");
    }
  }
  return 0;
}
 
 
 
void setDepth(int u, int d){
  if(u==default) return;
  D[u]=d;
  setDepth(T[u].left, d+1);
  setDepth(T[u].right, d+1);
}
 
int setHeight(int u) {
  int h1=0, h2=0;
  if(T[u].left != default)
    h1 = setHeight(T[u].left) + 1;
  if(T[u].right != default)
    h2 = setHeight(T[u].right) + 1;

  if(h1>h2)return H[u]=h1;
  else return H[u]=h2;
}
 
int getSibling(int u){
  if(T[u].parent == default) return default;
  if(T[T[u].parent].left != u && T[T[u].parent].left != default)
    return T[T[u].parent].left;
  if(T[T[u].parent].right != u && T[T[u].parent].right != default)
    return T[T[u].parent].right;
  return default;
}
