//binary tree
//2019-01-09
//Ebitani Akira

#include <stdio.h>
#include <stdlib.h>

#define N 100000

struct Node {int p, l, r; };
struct Node T[N];
int D[N];
int H[N];
int n;

void Depth(int, int);
int Height(int);
int Sbling(int);
void Print_tree(int);

int main (){
  int i, j;
  int root;
  int v, r, l;

  root = 0;
  scanf("%d", &n);
  if(n < 1 || n > 25){
    printf("節点の情報が適当ではありません。/n");
    exit(1);
  }
  
  for(i = 0 ; i < n ; i++)
    T[i].p = -1;
  
  for(i = 0 ; i < n ; i++){
    scanf("%d%d%d", &v, &l, &r);
    T[v].l = l;
    T[v].r = r;

    if(l != -1)
      T[l].p = v;
    if(r !=-1)
      T[r].p = v;
  }

  for(i = 0 ; i < n ; i++){
    if(T[i].p == -1)
      root = i;
  }

  Depth(root, 0);
  Height(root);
  for(i = 0 ; i < n ; i++){
    Print_tree(i);
  }

  return 0;
}
    
void Depth(int root, int i){
  if(root == -1)
    return;

  D[root] = i;
  Depth(T[root].l, i+1);
  Depth(T[root].r, i+1);

}

int Height(int root){
  int h_a, h_b;
  h_a = 0;
  h_b = 0;

  if(T[root].l != -1)
    h_a = Height(T[root].l) + 1;
  if(T[root].r != -1)
    h_b = Height(T[root].r) + 1;
  
  
  return H[root] = (h_a > h_b ? h_a : h_b);
}


int Sibling(int i){
  if(T[i].p == -1)
    return -1;
  if(T[T[i].p].l != i && T[T[i].p].l != -1)
    return T[T[i].p].l;
  if(T[T[i].p].r != i && T[T[i].p].r != -1)
    return T[T[i].p].r;

  return -1;
}

void Print_tree(int i){
  printf("node %d: ", i);
  printf("parent = %d, ", T[i].p);
  printf("sibling = %d, ", Sibling(i));

  int d = 0;
  if(T[i].l != -1)
    d++;
  if(T[i].r != -1)
    d++;

  printf("degree = %d, ", d);
  printf("depth = %d, ", D[i]);
  printf("height = %d, ", H[i]);

  if(T[i].p == -1)
    printf("root\n");
  else if(T[i].l == -1 && T[i].r == -1)
    printf("leaf\n");
  else
    printf("internal node\n");

}
