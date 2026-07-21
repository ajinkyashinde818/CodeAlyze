#include <stdio.h>

#define NMAX 25
#define NIL -1

struct Node{
  int parent;
  int left;
  int right;
};
struct Node T[NMAX];

int n,Depth[NMAX],Height[NMAX];

void Setdepth(int,int);
int Setheight(int);
int Getsib(int);
void print(int);

int main(void){
  int i,value,l,r,root = 0;

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    T[i].parent = NIL;
  }
  for(i = 0;i < n;i++){
    scanf("%d%d%d",&value,&l,&r);
    T[value].left = l;
    T[value].right = r;
    if(l != NIL) T[l].parent = value;
    if(r != NIL) T[r].parent = value;
  }

  for(i = 0;i < n;i++){
    if(T[i].parent == NIL){
      root = i;
    }
  }
  Setdepth(root,0);
  Setheight(root);

  for(i = 0;i < n;i++){
    print(i);
  }

  return 0;
}

void Setdepth(int u,int d){
  if(u == NIL) return;
  Depth[u] = d;
  Setdepth(T[u].left,d + 1);
  Setdepth(T[u].right,d + 1);
}

int Setheight(int u){
  int h1 = 0,h2 = 0;
  if(T[u].left != NIL){
    h1 = Setheight(T[u].left) + 1;
  }
  if(T[u].right != NIL){
    h2 = Setheight(T[u].right) + 1;
  }
  return Height[u] = (h1 > h2 ? h1 : h2);
}

int Getsib(int u){
  if(T[u].parent == NIL) return NIL;
  if(T[T[u].parent].left != u && T[T[u].parent].left != NIL) return T[T[u].parent].left;
  if(T[T[u].parent].right != u && T[T[u].parent].right != NIL) return T[T[u].parent].right;
  return NIL;
}

void print(int u){
  printf("node %d: parent = %d, sibling = %d, ",u,T[u].parent,Getsib(u));
  int deg = 0;
  if(T[u].left != NIL) deg++;
  if(T[u].right != NIL) deg++;
  printf("degree = %d, depth = %d, height = %d, ",deg,Depth[u],Height[u]);
  if(T[u].parent == NIL){
    printf("root\n");
  }else if(T[u].left == NIL && T[u].right == NIL){
    printf("leaf\n");
  }else{
    printf("internal node\n");
  }
}
