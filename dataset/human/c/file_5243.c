#include <stdio.h>
#define MAX 10000
#define NIL -1

typedef struct {
  int pr,left,right;
} node;

node T[MAX];
int n,D[MAX],H[MAX];

void setdepth(int u,int d){
  if(u == NIL) return;
  D[u] = d;
  setdepth(T[u].left,d+1); setdepth(T[u].right,d+1);
}

int setheight(int u){
  int h1=0,h2=0;
  if(T[u].left != NIL) h1 = setheight(T[u].left)+1;
  if(T[u].right != NIL) h2 = setheight(T[u].right)+1;
  if(h1 >= h2) return H[u] = h1;
  else return H[u] = h2;
}

int getsib(int u){
  if(T[u].pr == NIL) return NIL;
  if(T[T[u].pr].left != u && T[T[u].pr].left != NIL) return T[T[u].pr].left;
  if(T[T[u].pr].right != u && T[T[u].pr].right != NIL) return T[T[u].pr].right;
  return NIL;
}

void print(int u){
  int deg=0;
  printf("node %d: parent = %d, sibling = %d, ",u,T[u].pr,getsib(u));
  if(T[u].left != NIL) deg++; if(T[u].right != NIL) deg++;
  printf("degree = %d, depth = %d, height = %d, ",deg,D[u],H[u]);

  if(T[u].pr == NIL) printf("root\n");
  else if(T[u].left == NIL && T[u].right == NIL) printf("leaf\n");
  else printf("internal node\n");
}

int main(){
  int i=0,id,l,r,root=0;
  scanf("%d",&n);

  for(i=0;i<n;i++) T[i].pr = NIL;
  for(i=0;i<n;i++){
    scanf("%d %d %d",&id,&l,&r);
    T[id].left = l; T[id].right = r;
    if(l != NIL) T[l].pr = id; if(r != NIL) T[r].pr = id;
  }

  for(i=0;i<n;i++) if(T[i].pr == NIL) root = i;

  setdepth(root,0);
  setheight(root);

  for(i=0;i<n;i++) print(i);

  return 0;
}
