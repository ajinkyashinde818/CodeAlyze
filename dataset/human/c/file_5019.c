#include<stdio.h>
#include<stdlib.h>
typedef struct{
  int parent;
  int l,r;    // child
}node;
int sibling(int);
int degree(int);
int depth(int);
int height(int);
node *T;
int h_count;
int main(){
  int n, x, i;
  scanf("%d",&n);
  T = (node *)malloc(sizeof(node) * n);
  for(i=0; i<n; i++) T[i].parent = -1;
  for(i=0; i<n; i++){
    scanf("%d",&x);
    scanf("%d%d",&T[x].l,&T[x].r);
    T[T[x].l].parent = x;
    T[T[x].r].parent = x;
  }
  for(i=0; i<n; i++){
    h_count = 0;
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",
	   i,T[i].parent,sibling(i),degree(i),depth(i),height(i));
    if(T[i].parent == -1) printf("root\n");
    else if(T[i].l == -1 && T[i].r == -1) printf("leaf\n");
    else printf("internal node\n");
  }
  free(T);
  return 0;
}

int sibling(int x){
  if(T[x].parent == -1) return -1;
  if(T[T[x].parent].l == x) return (T[T[x].parent].r);
  else return (T[T[x].parent].l);
}

int degree(int x){
  int count=2;
  if(T[x].l == -1) count--;
  if(T[x].r == -1) count--;
  return count;
}

int depth(int x){
  int d_count = 0;
  while(T[x].parent != -1){
    x = T[x].parent;
    d_count++;
  }
  return d_count;
}

int height(int x){
  int y,z;
  if(T[x].l != -1) y = height(T[x].l) + 1;
  else y = 0;
  if(T[x].r != -1) z = height(T[x].r) + 1;
  else z = 0;
  if(y < z) return z;
  else return y;
}
