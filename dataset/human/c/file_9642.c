#include<stdio.h>
struct Node {
  int p,l,r;
};
void print(int);
#define NIL -1
struct Node T[100005];
int rec(int,int);
int n,F[100005];
int main(){
  scanf("%d",&n);
  int i,j,k,s,v,h,m;
  for(i=0;i<n;i++){
    T[i].p=NIL;
    T[i].l=NIL;
    T[i].r=NIL;
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&k,&s);
    for(j=0;j<s;j++){
      scanf("%d",&v);
      if(j==0){
	T[k].l=v;
      }else{
	T[h].r=v;
      }
      h=v;
      T[v].p=k;
    }
  }
  for(i=0;i<n;i++){
    if(T[i].p==NIL)m=i;
  }
  rec(m,0);
  for(i=0;i<n;i++){
    print(i);
  }
  return 0;
}
int rec(int u,int s){
  F[u]=s;
  if(T[u].r!=NIL) rec(T[u].r,s);
  if(T[u].l!=NIL) rec(T[u].l,s+1);
}
void print(int u){
  int i,c;
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].p);
  printf("depth = %d, ",F[u]);
  if(T[u].p==NIL)printf("root, ");
  else if(T[u].l==NIL)printf("leaf, ");
  else printf("internal node, ");
  printf("[");
  for(i=0,c=T[u].l;c!=NIL;i++,c=T[c].r){
    if(i)printf(", ");
    printf("%d",c);
  }
  printf("]\n");
}
