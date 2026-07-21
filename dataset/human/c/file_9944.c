#include<stdio.h>

#define MAX 100005
#define NIL -1

typedef struct node Node;
struct node{
  int parent;
  int left;
  int right;
};
Node T[MAX];
int Dep[MAX];

void print(int u){
  int i, child;
  printf("node %d: parent = %d, depth = %d, ", u, T[u].parent, Dep[u]);

  if(T[u].parent == NIL) printf("root, ");
  else if(T[u].left == NIL) printf("leaf, ");
  else printf("internal node, ");
  
  printf("[");
  for (i=0, child = T[u].left; child != NIL; i++, child = T[child].right){
    if(i != 0) printf(", ");
    printf("%d", child);
  }
  printf("]\n");
  
}

void calcDepth(int u, int p){
  Dep[u] = p;
  if(T[u].right != NIL) calcDepth(T[u].right, p);
  if(T[u].left != NIL) calcDepth(T[u].left, p+1);
}

int main(){
  int i, j, k, n;
  int id, sib, child;
  int root = NIL;
  scanf("%d",&n);
  for(i=0; i<n; i++){
    T[i].parent = NIL;
    T[i].left = NIL;
    T[i].right = NIL;
   }
  for(i=0; i<n; i++){
    scanf("%d%d",&id,&k);
    for(j=0, sib=NIL; j<k; j++){
      scanf("%d",&child);
      T[child].parent = id;
      if(j == 0) T[id].left = child;
      else T[sib].right = child;
      sib = child;
    }
  }

  for(i=0; i<n; i++){
    if(T[i].parent == -1) root = i;
    }

  calcDepth(root, 0);

  for(i=0; i<n; i++) print(i);
  return 0;
}
