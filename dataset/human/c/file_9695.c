#include<stdio.h>
#define MAX 100001
#define NIL -1

typedef struct{
  int parent;
  int left;
  int right;
}node;

node tree[MAX];
int D[MAX];

void print(int u){
  int i,c;
  printf("node %d: ",u);
  printf("parent = %d, ",tree[u].parent);
  printf("depth = %d, ",D[u]);
  if(tree[u].parent == NIL)printf("root,");
  else if(tree[u].left == NIL)printf("leaf,");
  else printf("internal node,");
  printf(" [");
  i=0;
  for(c=tree[u].left;c != NIL ;c = tree[c].right){
    if(i)printf(", ");
    printf("%d",c);
    i++;
}
  printf("]\n");
}

int rec(int u,int p){
  D[u] = p;
  if(tree[u].right != NIL)rec(tree[u].right,p);
  if(tree[u].left != NIL)rec(tree[u].left,p+1);
}

int main(){
  int i,j,d,v,c,left,right,datanum;
  scanf("%d",&datanum);
  for(i=0;i<datanum;i++)tree[i].left = tree[i].right = tree[i].parent = NIL;

  for(i=0;i<datanum;i++){
    scanf(" %d %d",&v,&d);
    for(j=0;j<d;j++){
      scanf("%d",&c);
      if(j==0)tree[v].left = c;
      else tree[left].right = c;
      left  = c;
      tree[c].parent = v;
}
}
  for(i=0;i<datanum;i++){
    if(tree[i].parent == NIL)right = i;
}
  rec(right,0);
  for(i=0;i<datanum;i++)print(i);

  return 0;
    }
