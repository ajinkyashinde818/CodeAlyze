#include<stdio.h>
#include<stdlib.h>
#define N 10000
#define M -1

int n,Parent[N],Right[N],Left[N],D[N],H[N];

int GetDepth(int);
void SetDepth(int,int);
int Height(int);
int Sibling(int);
void Print(int);

int main(){
  int i,v,d,l,r;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    Parent[i]=Right[i]=Left[i]=M;
  }
  for(i=0;i<n;i++){
    scanf("%d",&v);
    scanf("%d",&l);
    scanf("%d",&d);
    Left[v]=l;
    Right[v]=d;
    if(l!=M){
      Parent[l]=v;
    }
    if(d!=M){
      Parent[d]=v;
    }
  }
  for(i=0;i<n;i++){
    if(Parent[i]==M){
      r=i;
    }
  }
  SetDepth(r,0);
  Height(r);
  for(i=0;i<n;i++){
    Print(i);
  }
  return 0;
}

int GetDepth(int u){
  int d=0;
  while(Parent[u]!=M){
    u=Parent[u];
    d++;
  }
  return d;
}

void SetDepth(int u,int p){
  D[u]=p;
  if(Right[u]!=M){
    SetDepth(Right[u],p+1);
  }
  if(Left[u]!=M){
    SetDepth(Left[u],p+1);
  }
}

int Height(int u){
  int a=0,b=0;
  if(Right[u]!=M){
    a=Height(Right[u])+1;
  }
  if(Left[u]!=M){
    b=Height(Left[u])+1;
  }
  return H[u]=(a>b?a:b);
}

int Sibling(int u){
  if(Parent[u]==M){
    return M;
  }
  if(Left[Parent[u]]!=u && Left[Parent[u]]!=M){
    return Left[Parent[u]];
  }
  if(Right[Parent[u]]!=u && Right[Parent[u]]!=M){
    return Right[Parent[u]];
  }
  return M;
}

void Print(int u){
  int i,de=0,c;
  printf("node %d: ",u);
  printf("parent = %d, ",Parent[u]);
  printf("sibling = %d, ",Sibling(u));
  if(Left[u]!=M){
    de++;
  }
  if(Right[u]!=M){
    de++;
  }
  printf("degree = %d, ",de);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",H[u]);
  if(Parent[u]==M){
    printf("root\n");
  }
  else if(Left[u]==M && Right[u]==M){
    printf("leaf\n");
  }
  else{
    printf("internal node\n");
  }
}
