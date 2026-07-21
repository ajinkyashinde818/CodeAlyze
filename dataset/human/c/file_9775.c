#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int p;
  int d;
  int k;
  int *c;
}Tree;

Tree *T;

void rootedtree(int);
void depth(int);

int main(){
  int n,id,i,j,root;

  scanf("%d",&n);

  T = malloc(sizeof(Tree) * n);
  
  for(i = 0; i < n; i++){
    T[i].p = -1;
    T[i].d = 0;
  }
  
  for(i = 0; i < n; i++){
    scanf("%d",&id);
    rootedtree(id);
  }
  
 for(i = 0; i < n; i++){
    if(T[i].p == -1) root = i;
  }
  
  depth(root);
 
  for(i = 0; i < n; i++){
    printf("node %d: parent = %d, depth = %d, ",i,T[i].p,T[i].d);
    if(T[i].d == 0) printf("root, [");
    else if(T[i].k > 0) printf("internal node, [");
    else printf("leaf, [");

    if(T[i].k > 0){
      for(j = 0; j < T[i].k; j++){
	printf("%d",T[i].c[j]);
	if(j != T[i].k - 1) printf(", ");
      }
    }
      printf("]\n");
  }
  for(i = 0; i < n; i++)free(T[i].c);
  free(T);
  
  return 0;
}

void rootedtree(int id){
  int i;
  scanf("%d",&T[id].k);
  
  if(T[id].k > 0){
    T[id].c = malloc(sizeof(int) * T[id].k);
    for(i = 0; i < T[id].k; i++){
      scanf("%d",&T[id].c[i]);
      T[T[id].c[i]].p = id;
    }
  }
}

void depth(int id){
  int i;
  if(T[id].k > 0){
    for(i = 0; i < T[id].k; i++){
      T[T[id].c[i]].d = T[id].d + 1;
      depth(T[id].c[i]);
    }
  }
}
