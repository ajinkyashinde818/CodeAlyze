#include <stdio.h>
#define MAX 100005
#define NIL -1

int D[MAX];

struct node{
  int k;
  int parent;
  int left;
  int right;
};

struct node T[MAX];

void getDepth(int, int);
void print(int);

int main(){
  int n, m, i, j, temp, v, id, a;
  
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    T[i].parent = NIL;
    T[i].left = NIL;
    T[i].right = NIL;  
  }
  for(i = 0; i < n; i++){
    scanf("%d %d", &v, &m);
    for(j = 0; j < m; j++){
      scanf("%d",&id);
      if(j == 0){
	T[v].left = id;
      }
      if(j != 0){
	T[temp].right = id;
      }
      T[id].parent = v;
      temp = id;
    }
  }
  
  for(i = 0; i < n; i++){
    if(T[i].parent == NIL) a = i;
  }
  
  getDepth(a, 0);
  for(i = 0; i < n; i++){
    print(i);
  }
  
  return 0;
}

void getDepth(int u, int d){
  D[u] = d;
  if(T[u].left != NIL) getDepth(T[u].left, d + 1);
  if(T[u].right != NIL) getDepth(T[u].right, d);
}

void print(int u){
  int i, c, count;

  printf("node %d: ",u);
  printf("parent = %d, ",T[u].parent);
  printf("depth = %d, ",D[u]);

  if(T[u].parent == NIL){
    printf("root, ");
  }
  else if(T[u].left == NIL){
    printf("leaf, ");
  }
  else {
    printf("internal node, ");
  }
  printf("[");
  i = 0;
  for(c = T[u].left; c != NIL; c = T[c].right){
    if(i) printf(", ");
    printf("%d",c);
    i++;
  }
  printf("]\n");
}
