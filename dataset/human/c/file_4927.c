#include <stdio.h>
#define MAX 100005
#define NIL -1

typedef struct Node {
  int p;
  int l;
  int r;
}Node;

Node T[MAX];

int n,D[MAX],H[MAX];


int setHeight(int u){

  int h1=0,h2=0;

  if(T[u].l!=NIL) h1=setHeight(T[u].l)+1;
  if(T[u].r!=NIL) h2=setHeight(T[u].r)+1;

  return H[u]=(h1>h2?h1:h2);
}


void setDepth(int u,int p){
  if(u==NIL) return;

  D[u]=p;
  setDepth(T[u].r,p+1);
  setDepth(T[u].l,p+1);
}

int getSibling(int u){

  if(T[u].p==NIL) return NIL;

  if(T[T[u].p].l!=u && T[T[u].p].l!=NIL){
    return T[T[u].p].l;
  }

  if(T[T[u].p].r!=u && T[T[u].p].r!=NIL){
    return T[T[u].p].r;
  }

  return NIL;
}

int main(){
  int v,l,r,i,root=0,deg=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    T[i].p=NIL;
  }

  for(i=0;i<n;i++){

    scanf("%d %d %d", &v, &l, &r);

    T[v].l=l;
    T[v].r=r;

    if(l!=NIL)T[l].p=v;
    if(r!=NIL)T[r].p=v;

}
  for(i=0;i<n;i++){
    if(T[i].p==NIL) root=i;
  }

  setDepth(root,0);
  setHeight(root);

  for(i=0;i<n;i++){

    printf("node %d: parent = %d, sibling = %d, ",i,T[i].p,getSibling(i));

    if(T[i].l!=NIL)deg++;
    if(T[i].r!=NIL)deg++;

    printf("degree = %d, depth = %d, height = %d, ",deg,D[i],H[i]);

    if(T[i].p==NIL)printf("root");
else if(T[i].l==NIL&&T[i].r==NIL)printf("leaf");
    else printf("internal node");

    printf("\n");
    deg=0;
  }

  return 0;
}
