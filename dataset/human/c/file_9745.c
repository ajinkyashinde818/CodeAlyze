#include<stdio.h>
#define NILL -1

typedef struct
{
    int parent;
    int r; //sibling
    int l; //child
} TREE;

TREE t[100000];
int d[100000];

void depth(int node,int p)
{
    d[node] = p;
    if(t[node].r != NILL) depth(t[node].r,p);
    if(t[node].l != NILL) depth(t[node].l,p+1);
}

int main()
{
  int v,k;
  int vi;
  int child,sibl;
  int n;
  int i,j;
  
  scanf("%d",&n);
  
  for(i=0;i < n;i++){
    t[i].l = NILL;
    t[i].r = NILL;
    t[i].parent = NILL;
  }

  for(i=0;i < n;i++){

    scanf("%d%d",&v,&k);
    
    for(j=0;j < k;j++){

      scanf("%d",&vi);
      
      if(j == 0) t[v].l = vi;
      else t[child].r = vi;

      child = vi;
      t[vi].parent = v;
    }
  }

  //根を調べる
  for(i=0;i < n;i++){
    if(t[i].parent == NILL) sibl = i;
  }
  depth(sibl,0);

  for(i=0;i < n;i++){
    printf("node %d: parent = %d, depth = %d, ",i,t[i].parent,d[i]);
    if(t[i].parent == NILL) printf("root,");
    else if(t[i].l == NILL) printf("leaf,");
    else printf("internal node,");

    int vv=t[i].l;
    printf(" [");
    for(j=0;vv != NILL; vv=t[vv].r,j++){
      if(j) printf(", ");
      printf("%d",vv);
    }
    printf("]\n");
  }
  return 0;
}
