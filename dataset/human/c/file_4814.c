#include<stdio.h>
#define MAX 10001
#define NIL -1
int Height(int);
int Sibling(int);
void Depth(int,int);
void print(int);
struct Node{int p,l,r;};
struct Node T[MAX];
int n,D[MAX],H[MAX];

int main(){
  int i;
  int u,l,r,id;
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    T[i].p = NIL;
  }
  for(i = 0; i < n; i++){
    scanf("%d %d %d",&id,&l,&r);
    T[id].l = l;
    T[id].r = r;
    if(l != NIL) T[l].p = id;
    if(r != NIL) T[r].p = id;
  }

  for(i = 0; i < n; i++) if(T[i].p == NIL) u = i;
  Depth(u,0);
  Height(u);


  for(i = 0; i < n; i++) print(i);

  return 0;
}

void Depth(int u,int p){
  D[u] = p;
  if(T[u].r != NIL) Depth(T[u].r,p+1);
  if(T[u].l != NIL) Depth(T[u].l,p+1);
}

int Height(int u){
  int h1=0,h2=0;
  if(T[u].l != NIL) h1 = Height(T[u].l) + 1;
  if(T[u].r != NIL) h2 = Height(T[u].r) + 1;
  if(h1 > h2) return H[u] = h1;
  else return H[u] = h2;
}

int Sibling(int u){
  if(T[u].p == NIL) return NIL;
  if(T[T[u].p].l != u && T[T[u].p].l != NIL) return T[T[u].p].l;
  if(T[T[u].p].r != u && T[T[u].p].r != NIL) return T[T[u].p].r;
  return NIL;
}

void print(int u){
  int count;
  printf("node %d: parent = %d, sibling = %d, ",u,T[u].p,Sibling(u));
  count = 0;
  if(T[u].l != NIL) count++;
  if(T[u].r != NIL) count++;
  printf("degree = %d, depth = %d, height = %d, ",count,D[u],H[u]);
  if(T[u].p == NIL) printf("root\n");
  else if(T[u].l == NIL && T[u].r == NIL) printf("leaf\n");
  else printf("internal node\n");
}
