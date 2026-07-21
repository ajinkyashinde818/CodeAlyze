#include<stdio.h>

#define MAX 10000
#define NIL -1

struct Node{
  int parent;
  int left;
  int right;
};

struct Node T[MAX];

int H[MAX],D[MAX];

void depth(int , int);

int height(int);

int sibling(int);

void print(int);

int main(){
  int v,l,r,root=0;
  int num,i,j;
  

  scanf("%d",&num);

  for(i=0;i<num;i++) T[i].parent = NIL;

  for(i=0;i<num;i++){
    scanf("%d%d%d",&v,&l,&r);
    T[v].left = l;
    T[v].right = r;
    if(l != NIL) T[l].parent = v;
    if(r != NIL) T[r].parent = v;
  }


  for(i=0;i<num;i++) if(T[i].parent == NIL) root = i;

  depth(root,0);
  height(root);

  for(i=0;i<num;i++) print(i);

  return 0;

}

void depth (int x,int y){
  if(x == NIL) return;
  D[x] = y;
  depth (T[x].left,y+1);
  depth (T[x].right,y+1);
}

int height(int u)
{
  int h1=0;
  int h2=0;
  int value;

  if(T[u].left != NIL) h1 = height(T[u].left) + 1;
  if(T[u].right != NIL) h2 = height(T[u].right) + 1;

  if(h1 > h2) value = h1;
  else value = h2;
  return H[u] = value;
}

int sibling(int u){
  if(T[u].parent == NIL) return NIL;
  if(T[T[u].parent].left != u &&T[T[u].parent].left != NIL){
    return T[T[u].parent].left;
  }

  if(T[T[u].parent].right != u && T[T[u].parent].right != NIL){
    return T[T[u].parent].right;
  }

  return NIL;

}

void print(int u)
{

  int degree=0;
  
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].parent);
  printf("sibling = %d, ",sibling(u));

  if(T[u].left != NIL) degree++;
  if(T[u].right != NIL) degree++;
  printf("degree = %d, ",degree);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",H[u]);

  if(T[u].parent == NIL){
    printf("root\n");
  }

  else if(T[u].left == NIL && T[u].right == NIL){
    printf("leaf\n");
  }
  else printf("internal node\n");
}
