#include <stdio.h>

#define NMAX 100001
#define NIL -1

struct Node{
  int parent;
  int left;
  int right;
};

struct Node T[NMAX];

int n, Depth[NMAX];

void print(int);
int rec(int,int);

int main(void){
  int i,j,degree,value,c,l,r;

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    T[i].parent = T[i].left = T[i].right = NIL;
  }

  for(i = 0;i < n;i++){
    scanf("%d%d",&value,&degree);
    for(j = 0;j < degree;j++){
      scanf("%d",&c);
      if(j == 0){
	T[value].left = c;
      }else{
	T[l].right = c;
      }
      l = c;
      T[c].parent = value;
    }
  }

  for(i = 0;i < n;i++){
    if(T[i].parent == NIL){
      r = i;
    }
  }

  rec(r,0);

  for(i = 0;i < n;i++){
    print(i);
  }
  return 0;
}

void print(int u){
  int i,c;

  printf("node %d: parent = %d, depth = %d, ",u,T[u].parent,Depth[u]);

  if(T[u].parent == NIL){
    printf("root, ");
  }else if(T[u].left == NIL){
    printf("leaf, ");
  }else{
    printf("internal node, ");
  }
  printf("[");
  for(i = 0,c = T[u].left;c != NIL;i++,c = T[c].right){
    if(i == 0){
      printf("%d",c);
    }else{
      printf(", %d",c);
    }
  }
  printf("]\n");
}

int rec(int u,int p){
  Depth[u] = p;
  if(T[u].right != NIL){
    rec(T[u].right,p);
  }
  if(T[u].left != NIL){
    rec(T[u].left,p + 1);
  }
  return 0;
}
