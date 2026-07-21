#include<stdio.h>
#define MAX 25
#define NIL -1
int Height(int);
int Sibling(int);
void Depth(int,int);
void output(int);
struct Node{
  int parent;
  int left;
  int right;
};
struct Node T[MAX];
int n,d[MAX],h[MAX];

int main(){
  int i;
  int u,left,right,id;
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    T[i].parent = NIL;
  }
  for(i = 0; i < n; i++){
    scanf("%d %d %d",&id,&left,&right);
    T[id].left = left;
    T[id].right = right;
    if(left != NIL) T[left].parent = id;
    if(right != NIL) T[right].parent = id;
  }
  for(i = 0; i < n; i++) if(T[i].parent == NIL) u = i;
  Depth(u,0);
  Height(u);
  for(i = 0; i < n; i++) output(i);
  return 0;
}



void Depth(int u,int p){
  d[u] = p;
  if(T[u].right != NIL) Depth(T[u].right,p+1);
  if(T[u].left != NIL) Depth(T[u].left,p+1);
}

int Height(int u){
  int hh=0,H=0;
  if(T[u].left != NIL) hh = Height(T[u].left) + 1;
  if(T[u].right != NIL) H = Height(T[u].right) + 1;
  if(hh > H) return h[u] = hh;
  else return h[u] = H;
}

int Sibling(int u){
  if(T[u].parent == NIL) return NIL;
  if(T[T[u].parent].left != u && T[T[u].parent].left != NIL) return T[T[u].parent].left;
  if(T[T[u].parent].right != u && T[T[u].parent].right != NIL) return T[T[u].parent].right;
  return NIL;
}

void output(int u){
  int c;
  printf("node %d: parent = %d, sibling = %d, ",u,T[u].parent,Sibling(u));
  c = 0;
  if(T[u].left != NIL) c++;
  if(T[u].right != NIL) c++;
  printf("degree = %d, depth = %d, height = %d, ",c,d[u],h[u]);
  if(T[u].parent == NIL) printf("root\n");
  else if(T[u].left == NIL && T[u].right == NIL) printf("leaf\n");
  else printf("internal node\n");
}
