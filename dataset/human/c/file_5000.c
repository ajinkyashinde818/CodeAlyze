#include <stdio.h>
struct Node{int parent, left, right;};

struct Node T[10000];
int n, D[10000], H[10000];

void Depth(int u,int d){
  if(u == -1) return;
  D[u] = d;
  Depth(T[u].left, d+1);
  Depth(T[u].right, d+1);
}

int Height(int u){
  int h1 =0;
  int h2 = 0;
  if(T[u].left != -1){
    h1 = Height(T[u].left)+1;
  }
  if(T[u].right != -1){
    h2 = Height(T[u].right) + 1;
  }
  return H[u] = (h1 > h2 ? h1 : h2);
}

int Sibling(int u){
  if(T[u].parent == -1) {
    return -1;
  }
  if(T[T[u].parent].left != u && T[T[u].parent].left != -1){
    return T[T[u].parent].left;
  }
  if(T[T[u].parent].right != u && T[T[u].parent].right != -1){
     return T[T[u].parent].right;
  }
  return  -1;
}

int main(){
  int v,l,r,root=0,i;
  scanf("%d", &n);
  for (i =0;i< n;i++){
    T[i].parent = -1;
  }
  for (i = 0;i<n;i++){
    scanf("%d %d %d",&v,&l,&r);
    T[v].left = l;
    T[v].right =r;
    if(l != -1) T[l].parent = v;
    if (r != -1) T[r].parent =v;
  }
  for ( i = 0;i<n; i++){
    if(T[i].parent == -1) root = i;
  }

  Depth(root,0);
  Height(root);
  int d;
  for (i = 0;i<n;i++){
    printf("node %d: ",i);
    printf("parent = %d, ",T[i].parent);
    printf("sibling = %d, ",Sibling(i));
    d = 0;
    if(T[i].left != -1) d ++;
    if(T[i].right != -1) d++;
    printf("degree = %d, ",d);
    printf("depth = %d, ",D[i]);
    printf("height = %d, ",H[i]);

    if(T[i].parent == -1){
      printf("root\n");
    }
    else if(T[i].left == -1 && T[i].right == -1){
      printf("leaf\n");
    }
    else {
      printf("internal node\n");
    }
  }
  return 0;
  
}
