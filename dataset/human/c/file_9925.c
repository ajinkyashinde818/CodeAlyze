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
  int i,id,j,n,k,c[100000],depth=0,num;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    tree[i].parent=NIL;
    tree[i].left=NIL;
    tree[i].right=NIL;
  }

  for(i=0;i<n;i++){
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
  
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, ",i,tree[i].parent);
    num=i;
    while(tree[num].parent!=NIL){
      depth++;
      num=tree[num].parent;
    }
    printf("depth = %d,",depth);
    depth=0;
    if(tree[i].parent==NIL && tree[i].left==NIL){
       printf(" root, []\n");
    }
    else if(tree[i].parent==NIL && tree[i].left!=NIL){
      printf(" root, [%d",tree[i].left);
      for(j=tree[tree[i].left].right;j!=NIL;j=tree[j].right){
        printf(", %d",j);
      }
      printf("]\n");
    }
    else if(tree[i].left!=NIL){
      printf(" internal node, [%d",tree[i].left);
      for(j=tree[tree[i].left].right;j!=NIL;j=tree[j].right){
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
