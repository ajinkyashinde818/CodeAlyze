#include<stdio.h>
#define MAX 100000
#define NIL -1
struct node{
  int p;
  int l;
  int r;
};
struct node T[MAX];
int D[MAX];

void rec(int u,int p){
  D[u]=p;
  if(T[u].r!=NIL) rec(T[u].r,p);
  if(T[u].l!=NIL) rec(T[u].l,p+1);
}
void print(int u){
  int i,c;
  printf("node %d: parent = %d, depth = %d, ",u,T[u].p,D[u]);
  if(T[u].p==NIL) printf("root, ");
  else if(T[u].l==NIL) printf("leaf, ");
  else printf("internal node, ");

  printf("[");
  for(i=0,c=T[u].l;c!=NIL;i++,c=T[c].r){
    if(i) printf(", ");
    printf("%d",c);
  }
  printf("]\n");
}
int main(){

  int n,i,j,u,v,d,a,r,l;

  scanf("%d",&n);
  for(i=0;i<n;i++) T[i].p=T[i].l=T[i].r=NIL;

  for(i=0;i<n;i++){
    scanf("%d %d",&u,&v);
    for(j=0;j<v;j++){
      scanf("%d",&a);
      if(j==0) T[u].l=a;
      else T[l].r=a;
      l=a;
      T[a].p=u;
    }
  }
  for(i=0;i<n;i++){
    if(T[i].p==NIL) r=i;
  }

  rec(r,0);

  for(i=0;i<n;i++) print(i);

  return 0;
}
