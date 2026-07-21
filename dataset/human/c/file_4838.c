#include<stdio.h>
#define MAX 10000
#define NIL -1

struct Node_struct{int p, l, r;}; /*p: 親(parent), l: 一番左の子(left child), r\
				    :右の兄弟(right sibling)*/
typedef struct Node_struct Node;
Node T[MAX];
int n,D[MAX],H[MAX];

int Sibling(int u){
  if(T[u].p==NIL) return NIL;
  if(T[T[u].p].l!=u&&T[T[u].p].l!=NIL) return T[T[u].p].l;
  if(T[T[u].p].r!=u&&T[T[u].p].r!=NIL) return T[T[u].p].r;
  else return NIL;
}
void print(int u){
  int i,deg=0;
  printf("node %d: parent = %d, sibling = %d, ", u, T[u].p, Sibling(u));

  if(T[u].l!=NIL) deg++;
  if(T[u].r!=NIL) deg++;

  printf("degree = %d, depth = %d, height = %d, ",deg,D[u],H[u]);
  if(T[u].p==NIL) printf("root\n");
  else if(T[u].l==NIL&&T[u].r==NIL) printf("leaf\n");
  else printf("internal node\n");
}


void calcDepth(int u, int p){
  if(u==NIL) return;
  D[u] = p;
  if(T[u].l!=NIL) calcDepth(T[u].l,p+1);
  if(T[u].r!=NIL) calcDepth(T[u].r,p+1);
}
int Height(int u){
  int h1=0,h2=0;
  if(T[u].l!=NIL) h1=Height(T[u].l)+1;
  if(T[u].r!=NIL) h2=Height(T[u].r)+1;

  H[u]=(h1>h2?h1:h2);
  return H[u];
}

int main(){
  int n,i;
  int id,l,r;
  int root = 0;
  scanf("%d", &n);
  for(i=0; i<n; i++) T[i].p = NIL;

  for(i=0; i<n; i++){
    scanf("%d %d %d",&id,&l,&r);
    T[id].l=l;
    T[id].r=r;
    if(l!=NIL) T[l].p=id;
    if(r!=NIL) T[r].p=id;
  }
  for(i = 0;i<n;i++) if(T[i].p==NIL) root=i;

  calcDepth(root, 0);
  Height(root);

  for(i=0; i<n; i++) print(i);

  return 0;
}
