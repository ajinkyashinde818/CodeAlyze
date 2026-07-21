#include <stdio.h>
#define MAX 99999
#define NIL -1

struct Node{
  int parent,left,right;
};

struct Node T[MAX];
int n,D[MAX],H[MAX];//D:深さ,H:高さ。

void setDepth(int u,int d){
  if(u == NIL)
    return;
  D[u] = d;
  if(T[u].right != NIL)
    setDepth(T[u].right, d + 1);
  if(T[u].left != NIL)
    setDepth(T[u].left, d + 1);
}

int setHeight(int u){
  int h1 = 0,h2 = 0;
  if(T[u].right != NIL)
    h1 = setHeight(T[u].right) + 1;
  if(T[u].left != NIL)
    h2 = setHeight(T[u].left)+1;
  if(h1 > h2)
    return H[u] = h1;
  else
    return H[u] = h2;
}

int getSibling(int u){//uの兄弟を返す関数
  if(T[u].parent == NIL)
    return NIL;
  else if(T[T[u].parent].left == NIL || T[T[u].parent].right == NIL)
    return NIL;
  else if(T[T[u].parent].left == u)
    return T[T[u].parent].right;//再帰的に呼び出している
  else
    return T[T[u].parent].left;
}

void print(int u){
  int deg = 0;
  printf("node %d: ",u);
  printf("parent = %d, sibling = %d, ",T[u].parent, getSibling(u));
  if(T[u].left != NIL)
    deg++;
  if(T[u].right != NIL)
    deg++;
  printf("degree = %d, depth = %d, height = %d,",deg, D[u], H[u]);
  
  if (D[u] == 0) printf(" root\n");
  else if
    (H[u] == 0) printf(" leaf\n");
  else
    printf(" internal node\n");
}

int main(){
  int i,j;
  int v,l,r;
  int root;
  
  scanf("%d", &n);
  
  for(i = 0; i < n; i++)
    T[i].parent = NIL;
  
  for(i = 0; i < n; i++){
    scanf("%d %d %d",&v,&r,&l);
    T[v].left = l;
    T[v].right = r;
    if(l != NIL)
      T[l].parent = v;
    if(r != NIL)
      T[r].parent = v;
  }
  for(i = 0; i < n; i++){
    if(T[i].parent == NIL)
      root = i;
  }

    setDepth(root,0);
    setHeight(root);

    for(i = 0; i < n; i++)
      print(i);
    
  return 0;
}
