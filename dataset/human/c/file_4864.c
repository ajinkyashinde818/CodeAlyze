#include<stdio.h>
  
#define MAX 10000
  
typedef struct{
  
  int parent;
    
  int left;

  int right;

}Node;
  
Node T[MAX];

int D[MAX], H[MAX], n;
  
void setDepth(int,int);

int setHeight(int);

int getSibling(int);

void output(int);
  
int main(){

  int i, v, l, r, root;

  root = 0;
  
  scanf("%d",&n);
   
  for(i = 0; i < n; i++){

    T[i].parent = -1;
  }

  for(i = 0 ;i < n; i++){

    scanf("%d %d %d",&v,&l,&r);

    T[v].left = l;

    T[v].right = r;

    if(l != -1)T[l].parent = v;

    if(r != -1)T[r].parent = v;
  }
  
  for(i = 0 ; i < n; i++){

    if(T[i].parent == -1)
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

  D[u] = d;

  setDepth(T[u].left, d+1);

  setDepth(T[u].right,d+1);

}
  
int setHeight(int u){
  
  int h1,h2;
  
  h1 = h2 = 0;

  if(T[u].left != -1)h1 = setHeight(T[u].left) + 1;

  if(T[u].right != -1)h2 = setHeight(T[u].right) + 1;

  return H[u] = (h1 > h2 ? h1 : h2); 
}
  
int getSibling(int u){
  
  if(T[u].parent == -1)return -1;

  if(T[T[u].parent].left != u && T[T[u].parent].left != -1)
    return T[T[u].parent].left;

  if(T[T[u].parent].right != u && T[T[u].parent].right != -1)
    return T[T[u].parent].right;

  return -1;
}
  
void output(int u){

  int count;
  
  printf("node %d: parent = %d, sibling = %d, ",u,T[u].parent,getSibling(u));
  
  count = 0;
  
  if(T[u].left != -1)
    count++;
  if(T[u].right != -1)
    count++;
  
  printf("degree = %d, depth = %d, height = %d, ",count,D[u],H[u]);
  
  if(T[u].parent == -1)
    printf("root\n");

  else if(T[u].left == -1 && T[u].right == -1)
    printf("leaf\n");

  else 
    printf("internal node\n");

}
