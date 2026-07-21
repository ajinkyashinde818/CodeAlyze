#include <stdio.h>

#define MAX 10005
#define NIL -1

typedef struct node{
  int parent,left,right;
} Node;

Node T[MAX];
int N,D[MAX],H[MAX];

void setdepth(int,int);
int setheight(int);
int getsibling(int);
void print(int);

int main(){
  int id,l,r,i;
  int root = 0;

  scanf("%d",&N);

  for(i=0;i<N;i++)T[i].parent = NIL;

  for(i=0;i<N;i++){
    scanf("%d %d %d",&id,&l,&r);
    T[id].left = l;
    T[id].right = r;
    if( l != NIL) T[l].parent = id;
    if( r != NIL) T[r].parent = id;
  }

  for(i=0;i<N;i++) if(T[i].parent == NIL)root = i;

  setdepth(root,0);
  setheight(root);

  for(i=0;i<N;i++)print(i);

  return 0;
}

void setdepth(int n,int d){
  if(n == NIL)return;
  D[n] = d;
  setdepth(T[n].left,d + 1);
  setdepth(T[n].right,d + 1);
}

int setheight(int n){
  int h1 = 0;
  int h2 = 0;

  if( T[n].left != NIL) h1 = setheight(T[n].left) + 1;

  if( T[n].right != NIL) h2 = setheight(T[n].right) + 1;

  return H[n] = ( h1 > h2 ? h1 : h2 );
}

int getsibling(int n){
  if(T[n].parent == NIL)return NIL;
  if(T[T[n].parent].left != n && T[T[n].parent].left != NIL)return T[T[n].parent].left;
  if(T[T[n].parent].right != n && T[T[n].parent].right != NIL)return T[T[n].parent].right;

  return NIL;
}

void print(int n){
  int deg =0;
  printf("node %d: ",n);
  printf("parent = %d, ",T[n].parent);
  printf("sibling = %d, ",getsibling(n));

  if(T[n].left != NIL)deg++;
  if(T[n].right != NIL)deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",D[n]);
  printf("height = %d, ",H[n]);

  if(T[n].parent == NIL){
    printf("root\n");
  }

  else if(T[n].left == NIL && T[n].right == NIL){
    printf("leaf\n");
  }

    else {
      printf("internal node\n");
    }
}
