#include <stdio.h>
#define MAX 1000005
#define NIL -1

struct Node{
  int p,l,r;
} ;
struct Node tree[MAX];
int n,D[MAX];

void print(int u){
  int i,c;
  printf("node %d: parent = %d, depth = %d, ",u,tree[u].p,D[u]);
  if(tree[u].p==NIL){
    printf("root, ");
  }
  else if(tree[u].l==NIL){
    printf("leaf, ");
  }
  else{
      printf("internal node, ");
}
printf("[");
for(i=0,c=tree[u].l;c!=NIL;i++,c=tree[c].r) {
  if(i>0)printf(", ");
  printf("%d", c);
}
printf("]\n");
}

int rec(int num,int p){
  D[num] = p;
  if(tree[num].r!=NIL){
    rec(tree[num].r,p);
  }
  if(tree[num].l!=NIL){
    rec(tree[num].l,p+1);
  }
}
int main(){
  int i,j,d,c,v,l=0,r;
  scanf("%d",&n);

  for(i=0;i<n;i++){
    tree[i].p = NIL;
    tree[i].l = NIL;
    tree[i].r = NIL;
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&v,&d);
    for(j=0;j<d;j++){
      scanf("%d",&c);
      if(j==0){
        tree[v].l = c;
      }
      else {
        tree[l].r = c;
      }
      l = c;
      tree[c].p = v;
    }
  }
  for(i=0;i<n;i++){
    if(tree[i].p==NIL){
      r = i;
    }
  }
  rec(r,0);
  for(i=0;i<n;i++)print(i);
  return 0;
}
