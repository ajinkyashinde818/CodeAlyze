#include <stdio.h>
#define MAX 100005
#define NIL -1
typedef struct {
  int p;
  int l;
  int r;
}info;
info tree[MAX];
int n,D[MAX];

int rec(int u,int p){
  D[u]=p;
  if(tree[u].r != NIL )rec(tree[u].r,p);
  if(tree[u].l != NIL )rec(tree[u].l,p+1);
  
}
void print(int u){
  int i,c;
  printf("node %d: ",u);
  printf("parent = %d, ",tree[u].p);
  printf("depth = %d, ",D[u]);
  if(tree[u].p == NIL) printf("root, ");
  else if(tree[u].l ==NIL)printf("leaf, ");
  else printf("internal node, ");
  i=0;
  c=tree[u].l;
  printf("[");
  
   while(c!=NIL){
    if(i>0)printf(", ");
    printf("%d",c);
    i++;
    c=tree[c].r;
  }
  printf("]\n");
}

int main(){
  int i,j,d,v,c,l,r;

  scanf("%d",&n);
  for(i=0;i<n;i++)tree[i].p = tree[i].l = tree[i].r = NIL;
  for(i=0;i<n;i++){
    scanf("%d%d",&v,&d);
    for(j=0;j<d;j++){
      scanf("%d",&c);
      if(j==0)tree[v].l = c;
      else tree[l].r=c;
      l = c;
      tree[c].p = v;
    }
  }

  for(i=0;i<n;i++){
    if(tree[i].p ==NIL)r=i;
  }
  rec(r,0);
  for(i=0;i<n;i++)print(i);
   
  
  return 0;
}
