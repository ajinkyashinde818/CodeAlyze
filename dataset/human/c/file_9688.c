#include<stdio.h>
#define max 100005
#define nil -1

struct Node{
  int p,l,r;
};

struct Node T[max];
int n,D[max];

void print(int u){
  int i,c;
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].p);
  printf("depth = %d, ",D[u]);
  if(T[u].p==nil){
    printf("root, ");
  }
  else if(T[u].l == nil){
    printf("leaf, ");
  }
  else {
    printf("internal node, ");
  }
  printf("[");

for(i=0,c=T[u].l;c!=nil;i++,c=T[c].r){
  if(i){
    printf(", ");
  }
  printf("%d",c);
}
printf("]\n");
}

int rec(int u,int p){
  D[u] = p;
  if(T[u].r != nil){
    rec(T[u].r,p);
  }
  if(T[u].l != nil){
    rec(T[u].l,p+1);
  }
  return 0;
}


int main(){
  int i,j,d,v,c,l,r;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].p = T[i].l = T[i].r = nil;
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&v,&d);
    for(j=0;j<d;j++){
      scanf("%d",&c);
      if(j==0){
        T[v].l = c;
      }
      else {
        T[l].r =c;
      }
      l=c;
      T[c].p =v;
    }
  }
  for(i=0;i<n;i++){
    if(T[i].p==nil){
      r=i;
    }
  }
  rec(r,0);
  for(i=0;i<n;i++){
    print(i);
  }
  return 0;
}
