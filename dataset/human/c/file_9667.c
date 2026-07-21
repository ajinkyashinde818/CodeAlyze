#include <stdio.h>
#include <stdlib.h>

#define N 100000

typedef struct{
  int id;
  int k;
  int *c;
  int parent;
  int depth;


}NODE;

void tmpa(NODE *, int);
void parent(NODE *, int);
void depth(NODE *, int);

int main(){

  int i, j;
  int n, set;
  NODE a[N];
  
  scanf("%d", &n);
  
  for(i = 0; i < n; i++){
    scanf("%d%d", &a[i].id, &a[i].k);
    
    if(a[i].k > 0){
      a[i].c = (int *)malloc(sizeof(int) * a[i].k);
      
      for(j = 0; j < a[i].k; j++){
	scanf("%d", &a[i].c[j]);
      }
    }
    
  }
  
  tmpa(a, n);
  parent(a, n);

  for(i = 0; i < n; i++){
    if(a[i].parent == -1){
      a[i].depth = 0;
      set = i;
    }
  }

  depth(a, set);
  
  for(i = 0; i < n; i++){
    printf("node %d: parent = %d, depth = %d, ", a[i].id, a[i].parent, a[i].depth);
    if(a[i].parent == -1) printf("root, [");
    else if(a[i].k > 0) printf("internal node, [");
    else printf("leaf, [");

    if(a[i].k > 0){
      for(j = 0; j < a[i].k; j++){
	printf("%d", a[i].c[j]);
	if(j != a[i].k - 1) printf(", ");
	else printf("]\n");
      }

    }
    else printf("]\n");

  }  

  return 0;
}

void tmpa(NODE *a, int n){

  int i;
  NODE tmp;
  
  for(i = 0; i < n; i++){
    if(a[i].id != i){
      tmp = a[a[i].id];
      a[a[i].id] = a[i];
      a[i] = tmp;
    }
    
  }
  
}

void parent(NODE *a, int n){

  int i, j;

  for(i = 0; i < n; i++){
    a[i].parent = -1;
  }

  for(i = 0; i < n; i++){
    if(a[i].k > 0){
      for(j = 0; j < a[i].k; j++){
	a[a[i].c[j]].parent = a[i].id;
      }

    }

  }

}

void depth(NODE *a, int n){

  int i;

  if(a[n].k > 0){

    for(i = 0; i < a[n].k; i++){
      a[a[n].c[i]].depth = a[n].depth + 1;
      depth(a, a[n].c[i]);
    }

  }
    
}
