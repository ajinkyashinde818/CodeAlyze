#include<stdio.h>
#define MAX 100005
#define NIL -1
struct Node{int p,r,l;};
struct Node T[MAX];
int n,D[MAX];
int search(int,int);
void print(int);
int main(){
  int i,j,r;
  int v,d,c,l;
  scanf("%d",&n);
  for(i=0;i<n;i++)T[i].p=T[i].r=T[i].l=NIL;
  for(i=0;i<n;i++){
    scanf("%d%d",&v,&d);
    for(j=0;j<d;j++){
      scanf("%d",&c);
      if(j==0)T[v].l=c;//子供として
      else T[l].r=c;//兄弟として
      l=c;//?
      T[c].p=v;//親を設定
    }
  }
  for(i=0;i<n;i++){
    if(T[i].p==NIL)r=i;
  }
  search(r,0);
  for(i=0;i<n;i++)print(i);
  return 0;
}

int search(int u,int p){
  D[u]=p;
  //printf("%d\n",D[u]);
  if(T[u].r!=NIL)search(T[u].r,p);
  if(T[u].l!=NIL)search(T[u].l,p+1);
}

void print(int u){
  int i,c;
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].p);
  printf("depth = %d, ",D[u]);
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
