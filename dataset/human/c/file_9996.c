#include <stdio.h>
#define N 100005
#define NIL -1

typedef struct node {
  int p;
  int l;
  int r;
} Node;

Node no[N];
int n;
int d[N];

void output(int node){
  int i, left;
  printf("node %d: parent = %d, depth = %d, ", node, no[node].p, d[node]);

  if(no[node].p == NIL){
    printf("root, ");
  }else if(no[node].l == NIL){
    printf("leaf, ");
  }else{
    printf("internal node, ");
  }

  printf("[");
  
  for(i = 0, left = no[node].l; left != NIL; i++, left = no[left].r){
    if(i){
      printf(", ");
    }
    printf("%d", left);
  }
  printf("]\n");
}

int depth(int node, int parent){
  d[node] = parent;
  if(no[node].r != NIL){
    depth(no[node].r, parent);
  }
  if(no[node].l != NIL){
    depth(no[node].l, parent+1);
  }
}

int main(){
  int i, j, m, k;
  int node, num, x;

  scanf("%d", &n);
  
  for(i = 0; i < n; i++){
    no[i].p = NIL;
    no[i].l = NIL;
    no[i].r = NIL;
  }
  
  for(i = 0; i < n; i++){
    scanf("%d%d", &node, &num);
    for(j = 0; j < num; j++){
      scanf("%d", &x);
      if(j == 0){
	no[node].l = x;
      }else{
	no[m].r = x;
      }
      m = x;
      no[x].p = node;
    }
  }
  
  for(i = 0; i < n; i++){
    if(no[i].p == NIL){
      k = i;
    }
  }

  depth(k, 0);
  
  for(i = 0; i < n; i++){
    output(i);
  }
  
  return 0;
}
