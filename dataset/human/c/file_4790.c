#include<stdio.h>
#define MAX 100000
#define N -1

struct Node{int p,l,r;};
struct Node T[MAX];
int n,D[MAX],H[MAX];

void setDepth(int u,int d){
  if(u==N)return;
  D[u]=d;
  setDepth(T[u].l, d+1);

  setDepth(T[u].r, d+1);
}

int setHeight(int u){
  int h1 =0,h2=0;
  if(T[u].l!=N)h1=setHeight(T[u].l)+1;
  if(T[u].r!=N)h2=setHeight(T[u].r)+1;
  return H[u] = (h1>h2?h1:h2);
}

int getSibling(int u){
  if(T[u].p==N)return N;
  if(T[T[u].p].l!=u&&T[T[u].p].l!=N)
    return T[T[u].p].l;
  if(T[T[u].p].r!=u&&T[T[u].p].l!=N)
    return T[T[u].p].r;
  return N;
}

void print(int u){
  printf("node %d: parent = %d, sibling = %d, ",u,T[u].p,getSibling(u));
  int deg = 0;
  if(T[u].l!=N)deg++;
  if(T[u].r!=N)deg++;
  printf("degree = %d, depth = %d, height = %d, ",deg,D[u],H[u]);

  if(T[u].p==N){
    printf("root\n");
  }else if(T[u].l==N&&T[u].r==N){
    printf("leaf\n");
  }else {
    printf("internal node\n");
  }
}

int main(){
  int i,v,l,r,root=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)T[i].p=N;
  for(i=0;i<n;i++){
    scanf("%d %d %d",&v,&l,&r);
    T[v].l=l;
    T[v].r=r;
    if(l!=N)T[l].p=v;
    if(r!=N)T[r].p=v;
  }

  for(i=0;i<n;i++)if(T[i].p==N)root=i;
 
  setDepth(root,0);
  setHeight(root);

 
  for(i=0;i<n;i++)print(i);
  return 0;
}
