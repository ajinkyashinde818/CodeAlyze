#include<stdio.h>

#define MAX 10000
#define NIL -1

typedef struct node{
  int parent;
  int left;
  int right;
}Node;

Node array[MAX];

int num,dataD[MAX],dataH[MAX];
void Depth(int,int);
int Height(int);
int sibling(int);
void print(int);

int main(void){
  int v;
  int l;
  int r;
  int root = 0;
  int i;

  scanf("%d",&num);

  for(i = 0;i < num;i++){
    array[i].parent = NIL;
  }
    for(i = 0;i < num;i++){
      scanf("%d %d %d",&v,&l,&r);
      array[v].left = l;
      array[v].right = r;
      if(l != NIL){
        array[l].parent = v;
      }
      if(r != NIL){
        array[r].parent = v;
      }
    }
    for(i = 0;i < num;i++){
      if(array[i].parent == NIL){
        root = i;
      }
    }
      Depth(root,0);
      Height(root);
      for(i = 0;i < num;i++){
        print(i);
      }
      return 0;
}

void Depth(int u,int d){
  if(u == NIL){
    return;
  }
  dataD[u] = d;
  Depth(array[u].left,d + 1);
  Depth(array[u].right,d + 1);
}

int Height(int u){
  int h1 = 0;
  int h2 = 0;

  if(array[u].left != NIL){
    h1 = Height(array[u].left) + 1;
  }
  if(array[u].right != NIL){
    h2 = Height(array[u].right) + 1;
  }
  return dataH[u] = (h1 > h2 ? h1 : h2);
}

int sibling(int u){
  if(array[u].parent == NIL){
    return NIL;
  }
  if(array[array[u].parent].left != u && array[array[u].parent].left != NIL){
    return array[array[u].parent].left;
  }
  if(array[array[u].parent].right != u && array[array[u].parent].right != NIL){
    return array[array[u].parent].right;
  }
  return NIL;
}

void print(int u){
  int deg;

  printf("node %d: parent = %d, sibling = %d, ",u,array[u].parent,sibling(u));

  if(array[u].left != NIL){
    deg++;
  }
  if(array[u].right != NIL){
    deg++;
  }

  printf("degree = %d, depth = %d, height = %d, ",deg,dataD[u],dataH[u]);

  if(array[u].parent == NIL){
    printf("root\n");
  }
  else if(array[u].left == NIL && array[u].right == NIL){
    printf("leaf\n");
  }
  else{
    printf("internal node\n");
  }
}
