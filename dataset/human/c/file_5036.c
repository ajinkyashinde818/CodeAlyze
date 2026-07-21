#include<stdio.h>
typedef struct{
  int p;
  int left;
  int right;
} Tree;
Tree tree[10000];

#define NIL -1
int geth(int);
int main()
{
  int i,id,j,n,k,dep=0,num,l,r,deg=0,h=0;
 
  scanf("%d",&n);
 
  for(i=0;i<n;i++){
    tree[i].p=NIL;
  }
 
  for(i=0;i<n;i++){
    scanf("%d%d%d",&id,&l,&r);
    tree[id].left=l;
    tree[id].right=r;
    if(l!=NIL && r!=NIL){
      tree[l].p=id;
      tree[r].p=id;
    }
    else if(l!=NIL && r==NIL){
      tree[l].p=id;
    }
    else if(l==NIL && r!=NIL){
      tree[r].p=id;
    }
  }
   
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, ",i,tree[i].p);
    if(tree[i].p==NIL){
      printf("sibling = -1, ");
    }
    else if(tree[tree[i].p].left==i){
      printf("sibling = %d, ",tree[tree[i].p].right);
    }
    else{
      printf("sibling = %d, ",tree[tree[i].p].left);
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
    while(tree[num].p!=NIL){
      dep++;
      num=tree[num].p;
    }
    printf("depth = %d, ",dep);
    dep = 0;
 
    printf("height = ");
    h = geth(i);
    printf("%d,",h);
    
    if(tree[i].p==NIL){
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

int geth(int i)
{
  int k=0,l=0;
  if(tree[i].left==NIL && tree[i].right==NIL)return 0;

  if(tree[i].left!=NIL){
  k=geth(tree[i].left)+1;
  }
  if(tree[i].right!=NIL){
  l=geth(tree[i].right)+1;
  }
  if(k>l){
    
    return k;
  }
  else{
    return l;
  }
}
