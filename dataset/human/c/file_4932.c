#include<stdio.h>

#define max 25

struct node{
  int parent,left,right;
};

struct node T[max];
int T2[max],T3[max];

void depth(int,int);
int high(int);
int sibling(int);
void printtree(int);

void depth(int u,int dep)
{
  if(u == -1)
    return;
  T2[u] = dep;
  depth(T[u].left,dep+1);
  depth(T[u].right,dep+1);
}

int high(int u)
{
  int hl=0,hr=0;
  if(T[u].left != -1)
    hl = high(T[u].left) + 1;
  if(T[u].right != -1)
    hr = high(T[u].right) + 1;
  return T3[u] = (hl > hr ? hl : hr);
}

int sibling(int u)
{
  if(T[u].parent == -1)
    return -1;
  
  if(T[T[u].parent].left != u && T[T[u].parent].left != -1)
    return T[T[u].parent].left;

  if(T[T[u].parent].right != u && T[T[u].parent].right != -1)
    return T[T[u].parent].right;

  return -1;
}

void printtree(int u)
{
  int degree=0;
  
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].parent);
  printf("sibling = %d, ",sibling(u));
  if(T[u].left != -1)
    degree++;
  if(T[u].right != -1)
    degree++;
  printf("degree = %d, ",degree);
  printf("depth = %d, ",T2[u]);
  printf("height = %d, ",T3[u]);

  if(T[u].parent == -1) {
    printf("root\n");
  }else if(T[u].left == -1 && T[u].right == -1) {
    printf("leaf\n");
  }else{
    printf("internal node\n");
  }
}

  
int main()
{
  int i,n,hi,le,ri;
  int root = 0;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    T[i].parent = -1;

  for(i=0;i<n;i++) {
    scanf("%d%d%d",&hi,&le,&ri);
    T[hi].left = le;
    T[hi].right = ri;
    if(le != -1)
      T[le].parent = hi;
    if(ri != -1)
      T[ri].parent = hi;
  }

  for(i=0;i<n;i++) {
    if(T[i].parent == -1)
      root = i;
  }

  depth(root,0);
  high(root);

  for(i=0;i<n;i++)
    printtree(i);

  return 0;
}
