#include<stdio.h>
#define max 10000
#define nil -1

struct Node{
  int parent,left,right;
};

struct Node T[max];
int n,D[max],H[max];

void setDepth(int u,int d){
  if(u==nil)return;
  D[u] = d;
  setDepth(T[u].left,d+1);
  setDepth(T[u].right,d+1);
}

int setHeight(int u){
  int h1=0,h2=0;
  if(T[u].left != nil){
    h1 = setHeight(T[u].left)+1;
  }
  if(T[u].right != nil){
    h2 = setHeight(T[u].right)+1;
  }
  return H[u] = (h1>h2?h1:h2);
}

int getSibling(int u){
  if(T[u].parent == nil)return nil;
  if(T[T[u].parent].left != u && T[T[u].parent].left !=nil)
  return T[T[u].parent].left;
  if(T[T[u].parent].right != u && T[T[u].parent].right !=nil)
  return T[T[u].parent].right;

  return nil;
}

void print(int u){
  printf("node %d: ",u);
  printf("parent = %d, ", T[u].parent);
  printf("sibling = %d, ",getSibling(u) );
  int deg = 0;
  if(T[u].left != nil )deg++;
    if(T[u].right != nil )deg++;
    printf("degree = %d, ",deg );
    printf("depth = %d, ",D[u] );
    printf("height = %d, ",H[u] );

    if(T[u].parent == nil){
      printf("root\n" );
    }
  else if(T[u].left == nil && T[u].right== nil){
    printf("leaf\n" );
  }else {
    printf("internal node\n" );
  }
}

int main(){
  int v,l,r,root = 0,n;
  scanf("%d",&n);

  for(int i = 0;i<n;i++){
    T[i].parent = nil;
  }

  for(int i = 0;i<n;i++){
    scanf("%d %d %d", &v,&l,&r );
    T[v].left = l;
    T[v].right = r;
    if(l!=nil)T[l].parent =v;
    if(r!=nil)T[r].parent = v;
  }

  for(int i = 0;i<n;i++)if(T[i].parent ==nil)root =i;

  setDepth(root,0);
  setHeight(root);

  for(int i ;i <n;i++)print(i);

  return 0;
}
