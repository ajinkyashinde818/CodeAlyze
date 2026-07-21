#include<stdio.h>
#define NUM 25

typedef struct Node{
  int parent,left,right;
}Node;

Node T[NUM];
int n,A[NUM],B[NUM];

void depth(int a, int b){
  if(a == -1)
    return;

  A[a] = b;
  depth(T[a].left, b+1);
  depth(T[a].right, b+1);
}

int height(int a){
  int h1=0,h2=0;

  if(T[a].left != -1)
    h1 = height(T[a].left)+1;

  if(T[a].right != -1)
    h2 = height(T[a].right)+1;

  if(h1 > h2)
    return B[a] = h1;

  else
    return B[a] = h2;
}

int sibling(int a){
  if(T[a].parent == -1)
    return -1;

  if(T[T[a].parent].left != a && T[T[a].parent].left != -1)
    return T[T[a].parent].left;

  if(T[T[a].parent].right != a && T[T[a].parent].right != -1)
    return T[T[a].parent].right;

  return -1;
}

void print(int a){
  int d = 0;

  printf("node %d: parent = %d, sibling = %d, ", a, T[a].parent, sibling(a));

  if(T[a].left != -1)
    d++; 

  if(T[a].right != -1)
    d++;

  printf("degree = %d, depth = %d, height = %d, ", d, A[a], B[a]);


  if(T[a].parent == -1)
    printf("root\n");

  else if(T[a].left == -1 && T[a].right == -1)
    printf("leaf\n");

  else
    printf("internal node\n");
}

int main(){
  int a,l,ri,ro,i;

  scanf("%d", &n);

  for(i = 0; i < n; i++)
    T[i].parent = -1;

  for(i = 0;i < n; i++){
    scanf("%d%d%d", &a, &l, &ri);

    T[a].left = l;
    T[a].right = ri;

    if(l != -1)
      T[l].parent = a;

    if(ri != -1)
      T[ri].parent = a;
  }

  for(i = 0; i < n; i++){
    if(T[i].parent == -1)
      ro = i;
  }

  depth(ro, 0);
  height(ro);

  for(i = 0; i < n; i++)
    print(i);

  return 0;
}
