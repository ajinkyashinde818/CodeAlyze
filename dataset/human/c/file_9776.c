#include<stdio.h>

typedef struct{
  int parent;
  int left;
  int right;
} Tree;

Tree tree[1000000];

#define NIL -1

int main()
{
  int a,id,j,n,k,c[100000],depth=0,num;

  scanf("%d",&n);

  for(a=0;a<n;a++){
    tree[a].parent=NIL;
    tree[a].left=NIL;
    tree[a].right=NIL;
  }

  for(a=0;a<n;a++){
    scanf("%d%d",&id,&k);
    for(j=0;j<k;j++){
      scanf("%d",&c[j]);
      if(j==0){
	tree[c[0]].parent=id;
        tree[id].left=c[0];
      }
      else{
        tree[c[j]].parent=id;
        tree[c[j-1]].right=c[j];
      }
    }
  }
  
  for(a=0;a<n;a++){
    printf("node %d: parent = %d, ",a,tree[a].parent);
    num=a;
    while(tree[num].parent!=NIL){
      depth++;
      num=tree[num].parent;
    }
    printf("depth = %d,",depth);
    depth=0;
    if(tree[a].parent==NIL && tree[a].left==NIL){
      printf(" root, []\n");
    }
    else if(tree[a].parent==NIL && tree[a].left!=NIL){
      printf(" root, [%d",tree[a].left);
      for(j=tree[tree[a].left].right;j!=NIL;j=tree[j].right){
        printf(", %d",j);
      }
      printf("]\n");
    }
    else if(tree[a].left!=NIL){
      printf(" internal node, [%d",tree[a].left);
      for(j=tree[tree[a].left].right;j!=NIL;j=tree[j].right){
        printf(", %d",j);
      }
      printf("]\n");
    }
    
    else{
      printf(" leaf, []\n");
    }
    
  }
  return 0;
}
