#include <stdio.h>

struct Node{int p,l,r;};

struct Node T[10000];
int n,D[10000],H[10000];

void setDepth(int u,int d){
  if(u==-1){
    return;
  }
  D[u]=d;
  setDepth(T[u].l,d+1);
  setDepth(T[u].r,d+1);
}

int setHeight(int u){
  int h1=0,h2=0;
  if(T[u].l!=-1){
    h1=setHeight(T[u].l)+1;
  }
  if(T[u].r!=-1){
    h2=setHeight(T[u].r)+1;
  }
  return H[u]=(h1>h2?h1:h2);
}

int getSibling(int u){
  if(T[u].p==-1){
    return -1;
  }
  if(T[T[u].p].l!=u&&T[T[u].p].l!=-1){
    return T[T[u].p].l;
  }
  if(T[T[u].p].r!=u&&T[T[u].p].r!=-1){
    return T[T[u].p].r;
  }
  return -1;
}

void print(int u){
  printf("node %d: parent = %d, sibling = %d, ",u,T[u].p,getSibling(u));
  int deg=0;
  if(T[u].l!=-1){
    deg++;
  }
  if(T[u].r!=-1){
    deg++;
  }
  printf("degree = %d, depth = %d, height = %d, ",deg,D[u],H[u]);
  if(T[u].p==-1){
    printf("root\n");
  }
  else if(T[u].l==-1&&T[u].r==-1){
    printf("leaf\n");
  }
  else{
    printf("internal node\n");
  }
}

int main(){
  int i,va,le,ri,root=0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].p=-1;
  }
  for(i=0;i<n;i++){
    scanf("%d%d%d",&va,&le,&ri);
    T[va].l=le;
    T[va].r=ri;
    if(le!=-1){
      T[le].p=va;
    }
    if(ri!=-1){
      T[ri].p=va;
    }
  }
  for(i=0;i<n;i++){
    if(T[i].p==-1){
      root=i;
    }
  }
  setDepth(root,0);
  setHeight(root);
  for(i=0;i<n;i++){
    print(i);
  }

  return 0;
}
