#include<stdio.h>
#define N 100005
#define M -1
int n,Parent[N],Right[N],Left[N],D[N];

int GetDepth(int);
void SetDepth(int,int);
void Print(int);

int main(){
  int i,j,v,l,c,d,r;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    Parent[i]=Right[i]=Left[i]=M;
  }
  for(i=0;i<n;i++){
    scanf("%d",&v);
    scanf("%d",&d);
    for(j=0;j<d;j++){
      scanf("%d",&c);
      if(j==0){
	Left[v]=c;
      }
      else{
	Right[l]=c;
      }
      l=c;
      Parent[c]=v;
    }
  }
  
  for(i=0;i<n;i++){
    if(Parent[i]==M){
      r=i;
    }
  }
  SetDepth(r,0);
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
    SetDepth(Right[u],p);
  }
  if(Left[u]!=M){
    SetDepth(Left[u],p+1);
  }
}

void Print(int u){
  int i,c;
  printf("node %d: ",u);
  printf("parent = %d, ",Parent[u]);
  printf("depth = %d, ",GetDepth(u));
  if(Parent[u]==M){
    printf("root, ");
  }
  else if(Left[u]==M){
    printf("leaf, ");
  }
  else{
    printf("internal node, ");
  }
  printf("[");
  for(i=0,c=Left[u];c!=M;i++,c=Right[c]){
    if(i){
      printf(", ");
    }
    printf("%d",c);
  }
  printf("]\n");
}
