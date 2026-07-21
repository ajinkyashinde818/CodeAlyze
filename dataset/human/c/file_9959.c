#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000000
#define NIL -1

typedef struct{
  int pre;
  int left;
  int right;
} Node;

Node T[MAX];
int n, D[MAX];

void print(int u){
  int i, c;
  
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].pre);
  printf("depth = %d, ",D[u]);

  if(T[u].pre == NIL) printf("root, ");
  else if(T[u].left == NIL ) printf("leaf, ");
  else printf("internal node, ");

  printf("[");
  for(i = 0, c = T[u].left; c != NIL; i++, c = T[c].right){
    if(i) printf(", ");
    printf("%d",c);
  }
  printf("]\n");
}

int rec(int u, int p){
  D[u] = p;
  if(T[u].right != NIL) rec(T[u].right, p);
  if(T[u].left != NIL) rec(T[u].left, p+1);
}

int main(){
  int i, j, d, v, c, l, r;

  scanf("%d",&n);
  for(i = 0; i < n; i++) T[i].pre = T[i].left = T[i].right = NIL;

  for(i = 0; i < n; i++){
    scanf("%d%d",&v,&d);
    for(j = 0; j < d; j++){
      scanf("%d",&c);
      if (j == 0) T[v].left = c;
      else T[l].right = c;
      l = c;
      T[c].pre = v;
    }
  }

  for(i = 0; i < n; i++){
    if(T[i].pre == NIL) r = i;
  }

  rec(r,0);
  for(i = 0; i < n; i++) print(i);
  
  return 0;
}
