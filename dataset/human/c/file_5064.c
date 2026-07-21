#include <stdio.h>
#define N 10000

typedef struct{
  int id;
  int parent;
  int left;
  int right;
  int depth;
  int sibling;
  int height;
} Node;

Node T[N];
void Depth(int, int);
int Height(int);
void Sibling(int);

int main(){
  int root,n,i,id;

  scanf("%d",&n);
  for(i = 0; i < n; i++){
    T[i].parent = -1;
  }

  for(i = 0; i < n; i++){
    scanf("%d",&id);
    scanf(" %d %d",&T[id].left,&T[id].right);
    if(T[id].left != -1) T[T[id].left].parent = id;
    if(T[id].right != -1) T[T[id].right].parent = id;
  }

  for(i = 0; i < n; i++){
    if(T[i].parent == -1) root = i;
  }

  Depth(root,0);
  Height(root);
  Sibling(n);

  for(i = 0; i < n; i++){
    printf("node %d: parent = %d, sibling = %d, ",i,T[i].parent,T[i].sibling);
    printf("degree = ");
    if(T[i].left != -1 && T[i].right != -1) printf("2");
    else if(T[i].left != -1 || T[i].right != -1) printf("1");
    else printf("0");
  printf(", depth = %d, height = %d, ",T[i].depth,T[i].height);
    if(T[i].parent == -1) printf("root");
    else if(T[i].left == -1 && T[i].right == -1) printf("leaf");
    else printf("internal node");
    printf("\n");
  }
  return 0;
}

void Sibling(int n){
  int i;
  for(i = 0; i < n; i++){
    T[i].id = i;
  }
  for(i = 0; i < n; i++)
    if(T[i].parent == -1) T[i].sibling = -1;
    else if(T[T[i].parent].right != T[i].id) T[i].sibling = T[T[i].parent].right;
    else if(T[T[i].parent].left != T[i].id) T[i].sibling = T[T[i].parent].left;
  return;
}


void Depth(int child, int d){
  if(child == -1) return ;
  T[child].depth = d;
  Depth(T[child].left,++d);
  Depth(T[child].right,d);
}

int Height(int u){
  int a,b;
  a = b = 0;
  if(T[u].left != -1) a = 1 + Height(T[u].left);
  if(T[u].right != -1) b = 1 + Height(T[u].right);
  if(a < b){
    T[u].height = b;
    return b;
  }
  T[u].height = a;
  return a;
}
