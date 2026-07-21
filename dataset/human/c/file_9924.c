#include <stdio.h>
#include <stdlib.h>
#define N 100000

typedef struct{
  int id;
  int p;
  int c;
  int *child;
} Tree;

int n;
Tree *T;

int getdepth(int u){

  int d = 0;

  while(T[u].p >= 0){
    u = T[u].p;
    d++;
  }
  return d;
}

void print(void){

  int i,j,flag=0;

  for(i=0;i<n;i++){
    flag=0;

    printf("node %d: parent = %d, depth = %d, ",T[i].id,T[i].p,getdepth(i));
    if(T[i].c == 0 && T[i].p != -1)
      printf("leaf, [");
    else if(T[i].c != 0 && T[i].p != -1)
      printf("internal node, [");
    else 
      printf("root, [");

    for(j=0;j<T[i].c;j++){
      if(flag==0){ 
	printf("%d",T[i].child[j]);
	flag=1;
      }
      else {
	printf(", %d",T[i].child[j]);
      }
    }
    printf("]\n");
  }
}


int main(void){

  int i,j,node,deg;

  scanf("%d",&n);

  T = malloc(n * sizeof(Tree));

  for(i=0;i<n;i++){
    T[i].id = T[i].p = T[i].c = -1;    
  }

  for(i=0;i<n;i++){
    scanf("%d %d",&node,&deg);
    T[node].id = node;
    T[node].c = deg;
    T[node].child = malloc(deg * sizeof(int));
    for(j=0;j<deg;j++){
      scanf("%d",&T[node].child[j]);
      T[T[node].child[j]].p = node;
    } 
  }
  print();
  for(i=0;i<n;i++){
    free(T[i].child);
    }
  free(T);
  return 0; 
}
