#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

struct Node{
  int p;
  int l;
  int r;
};
void depth(int,int);
void print(int);

struct Node T[MAX];
int n, A[MAX];

int main(){
  int k,id,c,l,r;
  scanf("%d",&n);
  for(int i = 0; i < n; i++){
    T[i].r = -1;
    T[i].l = T[i].r;
    T[i].p = T[i].l;
  }
  for(int i = 0; i < n; i++){
    scanf("%d",&id);
    scanf("%d",&k);
    for(int j = 0; j < k; j++){
      scanf("%d",&c);
    if(j == 0){
      T[id].l = c;
    }
    else{
      T[l].r = c;
    }
    l = c;
    T[c].p = id;
    }
  }
  for(int i = 0; i < n; i++){
    if(T[i].p == -1){
      r = i;
    }
  }
  depth(r,0);
  for(int i = 0; i < n; i++){
    print(i);
  }
  return 0;
}

void depth(int u, int p){
  A[u] = p;
  if(T[u].r != -1){
    depth(T[u].r,p);
  }
  if(T[u].l != -1){
    depth(T[u].l , p+1);
  }
}

void print(int u){

  printf("node %d: ",u);
  printf("parent = %d, ",T[u].p);
  printf("depth = %d, ",A[u]);
  if(T[u].p == -1){
    printf("root, ");
  }
  else if(T[u].l == -1){
    printf("leaf, ");
  }
  else{
    printf("internal node, ");
  }
  printf("[");
  for(int i = 0, c = T[u].l; c != -1; i++, c = T[c].r){
    if(0 < i){
      printf(", ");
    }
    printf("%d",c);
  }
  printf("]\n");
}
