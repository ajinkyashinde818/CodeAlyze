#include <stdio.h>
#define N 100000
#define NIL -1

struct Node
{int p;
  int l;
  int r;
};

struct Node T[N];
int n,D[N],H[N];

int setDepth(int u, int p){
  if (u==NIL) return 0;
  D[u]=p;
  setDepth(T[u].l, p+1);
  setDepth(T[u].r, p+1);
}

int setHeight(int u){
  int h1=0,h2=0;
  if(T[u].l!=NIL)
    h1=setHeight(T[u].l)+1;
  if(T[u].r!=NIL)
    h2=setHeight(T[u].r)+1;
  return H[u]=(h1>h2?h1:h2);
}

int getSibling(int u){
  if(T[u].p==NIL) return NIL;
  if(T[T[u].p].l!=u && T[T[u].p].l!=NIL)
    return T[T[u].p].l;
  if(T[T[u].p].r!=u && T[T[u].p].r!=NIL)
    return T[T[u].p].r;
  return NIL;
}

void print(int u){
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].p);
  printf("sibling = %d, ",getSibling(u));
  int deg=0;
  if (T[u].l!=NIL) deg++;
  if (T[u].r!=NIL) deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",H[u]);
  
  if(T[u].p==NIL) printf("root\n");
  else if (T[u].l==NIL && T[u].r==NIL) printf("leaf\n");
  else printf("internal node\n");
}

int main(){
  int i,v,l,r,root=0;
  scanf("%d",&n);
  for(i=0;i<n;i++) T[i].p=NIL;

  for(i=0;i<n;i++){
    scanf("%d %d %d",&v,&l,&r);
    T[v].l=l;
    T[v].r=r;
    if(l!=NIL) T[l].p=v;
    if(r!=NIL) T[r].p=v;
  }

  for(i=0;i<n;i++) if(T[i].p==NIL) root=i;

  setDepth(root, 0);
  setHeight(root);

  for(i=0;i<n;i++) print(i);
    
  return 0;
}
