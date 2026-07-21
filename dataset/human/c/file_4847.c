#include<stdio.h>

#define MAX 10000

int NIL = -1;

typedef struct {
  int parent;
  int left,right;
} Node;

Node T[MAX];
int n;
int D[MAX],H[MAX];

void depth(int u,int p){
  if(u == NIL)return;
  D[u] = p;

  depth(T[u].left,p+1);
  depth(T[u].right,p+1);
}

int height(int u){
  int h1 = 0;
  int h2 = 0;

  if(T[u].left != NIL){
    h1 = height(T[u].left)+1;
  }  
  if(T[u].right != NIL){
    h2 = height(T[u].right)+1;
  }

  if(h1 > h2){
    H[u] = h1;
  } else {
    H[u] = h2;
  }
  
  return H[u];
}

int sibling(int u){
  if(T[u].parent == NIL)return NIL;
  
  if(T[T[u].parent].left != u && T[T[u].parent].left != NIL){
    return T[T[u].parent].left;
  }
  if(T[T[u].parent].right != u && T[T[u].parent].right != NIL){
    return T[T[u].parent].right;
  }
  
  return NIL;
}

void get(int u){
  int deg = 0;
  
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].parent);
  printf("sibling = %d, ",sibling(u));

  if(T[u].left != NIL)deg++;
  if(T[u].right != NIL)deg++;
  
  printf("degree = %d, ",deg);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",H[u]);

  if(T[u].parent == NIL){
    puts("root");
  } else if(T[u].left == NIL && T[u].right == NIL){
    puts("leaf");
  } else {
    puts("internal node");
  }
}

  
  
int main(void){
  int i = 0;
  int l,r,v;
  int root = 0;
  
  scanf("%d",&n);

  for(i = 0;i < n;i++){
    T[i].parent = NIL;
  }
  
  for(i = 0;i < n;i++){
    scanf("%d %d %d",&v,&l,&r);
    
    T[v].left = l;
    T[v].right = r;
    if(l != NIL){
      T[l].parent = v;
    }
    if(r != NIL){
      T[r].parent = v;
    }
  }
  
  for(i = 0;i < n;i++)
    if(T[i].parent == NIL){
      root = i;
    }
    
  depth(root,0);
  height(root);

  for(i = 0;i < n;i++){
    get(i);
  }

  return 0;
}
