#include <stdio.h>
#define M 100005
#define NL -1

typedef struct Node {
  int p;
  int l;
  int r;
}N;

N T[M];
int D[M],H[M];


int sH(int u){
  int h1=0,h2=0;
  if(T[u].l!=NL)h1=sH(T[u].l)+1;
  if(T[u].r!=NL)h2=sH(T[u].r)+1;
  return H[u]=(h1>h2?h1:h2);
}


void sD(int u,int p){
  if(u==NL)return;
  D[u]=p;
  sD(T[u].r,p+1);
  sD(T[u].l,p+1);
}

int gS(int u){
  if(T[u].p==NL)return NL;
  if(T[T[u].p].l!=u&&T[T[u].p].l!=NL)
    return T[T[u].p].l;
 if(T[T[u].p].r!=u&&T[T[u].p].r!=NL)
    return T[T[u].p].r;
  return NL;
}




int main(){
  int i,j,n,v,l,r,root=0,deg=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    T[i].p=NL;

  for(i=0;i<n;i++){
scanf("%d%d%d",&v,&l,&r);

    T[v].l=l;
    T[v].r=r;
    if(l!=NL)T[l].p=v;
    if(r!=NL)T[r].p=v;

  }
  for(i=0;i<n;i++)
    if(T[i].p==NL)root=i;

  sD(root,0);
  sH(root);

  for(i=0;i<n;i++){
    printf("node %d: parent = %d, sibling = %d, ",i,T[i].p,gS(i));
if(T[i].l!=NL)deg++;
    if(T[i].r!=NL)deg++;

    printf("degree = %d, depth = %d, height = %d, ",deg,D[i],H[i]);

    if(T[i].p==NL)printf("root");
    else if(T[i].l==NL&&T[i].r==NL)printf("leaf");
    else printf("internal node");

    printf("\n");
    deg=0;

  }
  return 0;
}
