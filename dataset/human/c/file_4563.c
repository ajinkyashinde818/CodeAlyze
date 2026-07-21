#include <stdio.h>
#define MAX 100005
#define NIL -1

typedef struct Node {
  int p;
  int l;
  int r;
}N;

N T[MAX];
int D[MAX],H[MAX];


int setHei(int u){
  int h1=0,h2=0;
  if(T[u].l!=NIL)h1=setHei(T[u].l)+1;
  if(T[u].r!=NIL)h2=setHei(T[u].r)+1;
  return H[u]=(h1>h2?h1:h2);
}


void setDep(int u,int p){
  if(u==NIL)return;
  D[u]=p;
  setDep(T[u].r,p+1);
  setDep(T[u].l,p+1);
}

int getSib(int u){
  if(T[u].p==NIL)return NIL;
  if(T[T[u].p].l!=u&&T[T[u].p].l!=NIL)
    return T[T[u].p].l;
 if(T[T[u].p].r!=u&&T[T[u].p].r!=NIL)
    return T[T[u].p].r;
  return NIL;
}

int main(){
  int i,j,n,k,l,r,root=0,deg=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    T[i].p=NIL;

  for(i=0;i<n;i++){
scanf("%d%d%d",&k,&l,&r);

    T[k].l=l;
    T[k].r=r;
    if(l!=NIL)T[l].p=k;
    if(r!=NIL)T[r].p=k;

  }
  for(i=0;i<n;i++)
    if(T[i].p==NIL)root=i;

  setDep(root,0);
  setHei(root);

  for(i=0;i<n;i++){
    printf("node %d: parent = %d, sibling = %d, ",i,T[i].p,getSib(i));
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
