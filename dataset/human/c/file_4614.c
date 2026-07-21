#include <stdio.h>
# define N 100000
# define node0 -1
int sibilings(int);
int degree(int);
int depth(int);
int hight(int);

typedef struct{
  int parent;
  int left;
  int right;
} tree_node;
tree_node tree[N];

int sibilings(int);
int degree(int);
int depth(int);
int hight(int);

int main(){
  int i,j,n;
  int par,Lef,Rig;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    tree[i].parent=node0;
    tree[i].left=node0;
    tree[i].right=node0;
  }
  for(i=0;i<n;i++){
    scanf("%d",&par);
     scanf("%d",&Lef);
      scanf("%d",&Rig);
      tree[Lef].parent=par;
      tree[Rig].parent=par;
      tree[par].left=Lef;
      tree[par].right=Rig;
  }
  for(i=0;i<n;i++){
     printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,tree[i].parent,sibilings(i),degree(i),depth(i),hight(i));
    if(tree[i].parent==node0){
      printf("root\n");
    }
    else if(tree[i].left==node0 && tree[i].right==node0){
	printf("leaf\n");
      }
    else printf("internal node\n");
  }
  return 0;
}
int sibilings(int nodeNum){
  if(tree[nodeNum].parent==node0){
    return node0;
  }
  else if(tree[tree[nodeNum].parent].left==nodeNum){
    return tree[tree[nodeNum].parent].right;
		}
  else return tree[tree[nodeNum].parent].left;
}
int degree(int nodeNum){
  if(tree[nodeNum].left==node0 && tree[nodeNum].right==node0){
    return 0;
  }
  else if(tree[nodeNum].left!=node0 && tree[nodeNum].right!=node0){
    return 2;
  }
  else{
    return 1;
  }
}
  int depth(int nodeNum){
    int count=0;
    if(tree[nodeNum].parent==node0){
      return 0;
    }
    else{
      count=depth(tree[nodeNum].parent)+1;
      return count;
    }
  }

  int hight(int nodeNum){
    int leftHight=0,rightHight=0;
    if(tree[nodeNum].left!=node0){
      leftHight=hight(tree[nodeNum].left)+1;
    }
    
   if(tree[nodeNum].right!=node0){
      rightHight=hight(tree[nodeNum].right)+1;
     }
   if(leftHight>rightHight){
     return leftHight;
   }
   else return rightHight;
  }
