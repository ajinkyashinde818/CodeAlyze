#include<stdio.h>
#include<stdlib.h>

#define N 10000
#define NIL -1

typedef struct Node{
  int parent;
  int right;
  int left;
}node;
  
node A[N];
int n, depth[N], height[N];

void setdepth(int, int);
int setheight(int);
int getsibling(int);

int main(){
  int left, right, num, root, i, degree, sibling;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    A[i].parent = NIL;
    A[i].left = NIL;
    A[i].right = NIL;
  }

  for(i = 0; i < n; i++){
    scanf("%d%d%d", &num, &left, &right);

    A[num].left = left;
    A[num].right = right;
    
    if(left != NIL)
      A[left].parent = num;
    if(right != NIL)
      A[right].parent = num;
  }
  for(i = 0; i < n; i++)
    if(A[i].parent == NIL)
      root = i;

  setdepth(root, 0);
  setheight(root);

  for(i = 0; i < n; i++){
    printf("node %d: parent = %d, sibling = %d, ", i, A[i].parent, getsibling(i));

    degree = 0;
    if(A[i].left != NIL)
      degree++;
    if(A[i].right != NIL)
      degree++;

    printf("degree = %d, depth = %d, height = %d, ", degree, depth[i], height[i]);

    if(A[i].parent == NIL)
      printf("root\n");
    else if(A[i].left == NIL && A[i].right == NIL)
      printf("leaf\n");
    else
      printf("internal node\n");
  }
  
  return 0;
}

void setdepth(int i, int d){
  if(i == NIL)
    return;

  depth[i] = d;

  setdepth(A[i].left, d + 1);
  setdepth(A[i].right, d + 1);
}

int setheight(int i){
  int h1 = 0, h2 = 0;

  if(A[i].left != NIL)
    h1 = setheight(A[i].left) + 1;
  if(A[i].right != NIL)
    h2 = setheight(A[i].right) + 1;

  if(h1 >= h2)
    return height[i] = h1;

  if(h2 > h1)
    return height[i] = h2;
}

int getsibling(int i){
  if(A[i].parent == NIL)
    return NIL;

  if(A[A[i].parent].left != i)
    return A[A[i].parent].left;

  if(A[A[i].parent].right != i)
    return A[A[i].parent].right;
}
