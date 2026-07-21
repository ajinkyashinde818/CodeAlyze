#include<stdio.h>
   
#define MAX 10000
   
typedef struct{
   
  int parent;
  int left;
  int right;
 
}Node;
   
Node A[MAX];
int B[MAX], C[MAX], n;
   
void setDepth(int,int);
int setHeight(int);
int getSibling(int);
void output(int);
int main(){
 
  int i, v, l, r, root;
  root = 0;
   
  scanf("%d",&n);
    
  for(i = 0; i < n; i++){
 
    A[i].parent = -1;
  }
 
  for(i = 0 ;i < n; i++){
    scanf("%d %d %d",&v,&l,&r);
    A[v].left = l;
    A[v].right = r;
    if(l != -1)A[l].parent = v;
    if(r != -1)A[r].parent = v;
  }
   
  for(i = 0 ; i < n; i++){
    if(A[i].parent == -1)
      root = i;
 
  }
    
  setDepth(root,0);
  setHeight(root);
   
  for(i = 0; i < n; i++){
 
    output(i);
 
  }
  return 0;
}
   
void setDepth(int u, int d){
   
  if(u == -1)
    return;
  B[u] = d;
  setDepth(A[u].left, d+1);
  setDepth(A[u].right,d+1);
}
   
int setHeight(int u){
  int h1,h2;
  h1 = h2 = 0;
  if(A[u].left != -1)h1 = setHeight(A[u].left) + 1;
  if(A[u].right != -1)h2 = setHeight(A[u].right) + 1;
  return C[u] = (h1 > h2 ? h1 : h2); 
}
   
int getSibling(int u){
  if(A[u].parent == -1)return -1;
  if(A[A[u].parent].left != u && A[A[u].parent].left != -1)
    return A[A[u].parent].left;
 
  if(A[A[u].parent].right != u && A[A[u].parent].right != -1)
    return A[A[u].parent].right;
 
  return -1;
}
   
void output(int u){
  int count;
  printf("node %d: parent = %d, sibling = %d, ",u,A[u].parent,getSibling(u));
  count = 0;
   
  if(A[u].left != -1)
    count++;
  if(A[u].right != -1)
    count++;
   
  printf("degree = %d, depth = %d, height = %d, ",count,B[u],C[u]);
   
  if(A[u].parent == -1)
    printf("root\n");
 
  else if(A[u].left == -1 && A[u].right == -1)
    printf("leaf\n");
 
  else
    printf("internal node\n");
 
}
