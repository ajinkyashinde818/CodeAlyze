#include<stdio.h>
typedef struct{
  int parent;
  int left;
  int right;
} Tree;
Tree tree[10000];
//int s=0,t=0;
#define NIL -1
int getheight(int);
int main()
{
  int i,id,j,n,k,depth=0,num,l,r,degree=0,height=0;
 
  scanf("%d",&n);
 
  for(i=0;i<n;i++){
    tree[i].parent=NIL;
  }
 
  for(i=0;i<n;i++){
    scanf("%d%d%d",&id,&l,&r);
    tree[id].left=l;
    tree[id].right=r;
    if(l!=NIL && r!=NIL){
      tree[l].parent=id;
      tree[r].parent=id;
    }
    else if(l!=NIL && r==NIL){
      tree[l].parent=id;
    }
    else if(l==NIL && r!=NIL){
      tree[r].parent=id;
    }
  }
   
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, ",i,tree[i].parent);
    if(tree[i].parent==NIL){
      printf("sibling = -1, ");
    }
    else if(tree[tree[i].parent].left==i){
      printf("sibling = %d, ",tree[tree[i].parent].right);
    }
    else{
      printf("sibling = %d, ",tree[tree[i].parent].left);
    }
    printf("degree = ");
    if(tree[i].left!=NIL && tree[i].right!=NIL){
      printf("2, ");
    }
    else if(tree[i].left==NIL && tree[i].right==NIL){
      printf("0, ");
    }
    else printf("1, ");
 
    num=i;
    while(tree[num].parent!=NIL){
      depth++;
      num=tree[num].parent;
    }
    printf("depth = %d, ",depth);
    depth=0;
 
    printf("height = ");
    height=getheight(i);
    printf("%d,",height);
    //s=0;t=0;
     
    if(tree[i].parent==NIL){
      printf(" root\n");
    }
    else if(tree[i].left==NIL && tree[i].right==NIL){
      printf(" leaf\n");
    }
    else {
      printf(" internal node\n");
      }
  }
  return 0;
}

int getheight(int i)
{
  int s=0,t=0;
  if(tree[i].left==NIL && tree[i].right==NIL)return 0;

  if(tree[i].left!=NIL){
  s=getheight(tree[i].left)+1;
  }
  if(tree[i].right!=NIL){
  t=getheight(tree[i].right)+1;
  }
  if(s>t){
    
    return s;
  }
  else{
    return t;
  }
}
