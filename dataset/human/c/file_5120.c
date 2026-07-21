#include <stdio.h>
#define N 25
#define NIL -1

struct Node{
  int p;
  int l;
  int r;
};

struct Node T[N];
int D[N],H[N];

void print(int);
void setDepth(int, int);
int setHeight(int);
int getSibling(int);

int main(){
  int n,i,id,l,r,root=0;
  scanf("%d",&n);

  for(i=0;i<n;i++) T[i].p = T[i].l = T[i].r = NIL;

  for(i=0;i<n;i++){
    scanf("%d%d%d",&id,&l,&r);
    T[id].l=l;
    T[id].r=r;
    if(l!=NIL) T[l].p=id;
    if(r!=NIL) T[r].p=id;
  }

  for(i=0;i<n;i++){
    if(T[i].p==NIL) root=i;
  }

  setDepth(root,0);
  setHeight(root);

  for(i=0;i<n;i++) print(i);

  return 0;
}


void print(int u){
  printf("node %d: parent = %d, sibling = %d, ",u,T[u].p,getSibling(u));
  int deg=0;
  if(T[u].l != NIL) deg++;
  if(T[u].r != NIL) deg++;
  printf("degree = %d, depth = %d, height = %d, ",deg,D[u],H[u]);

  if(T[u].p==NIL) printf("root\n");
  else if(T[u].l==NIL && T[u].r==NIL) printf("leaf\n");
  else printf("internal node\n");
}

void setDepth(int u, int d){
  if(u==NIL) return;
  D[u]=d;
  if(T[u].r!=NIL) setDepth(T[u].r, d+1);
  if(T[u].l!=NIL) setDepth(T[u].l, d+1);
}

int setHeight(int u){
  int h1=0,h2=0;
  if(T[u].l != NIL) h1=(setHeight(T[u].l)+1);
  if(T[u].r != NIL) h2=(setHeight(T[u].r)+1);
  H[u] = (h1>h2 ? h1:h2);
  return H[u];
}

int getSibling(int u){
  if(T[u].p==NIL) return NIL;
  if(T[T[u].p].l != u && T[T[u].p].l != NIL) return T[T[u].p].l;
  if(T[T[u].p].r != u && T[T[u].p].r != NIL) return T[T[u].p].r;
  return NIL;
}
