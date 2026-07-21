#include<stdio.h>
#define null -1

int sibling(int);
int degree(int);
int Height(int);
int depth(int);
void print(int);

typedef struct{
  int parent,left,right;
}node;

node tree[25];
int height[25];

int main(){
  int i,j;
  int n;
  int id;
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    tree[i].parent=tree[i].right=tree[i].left=null;
  }
  for(i=0;i<n;i++) {
    scanf("%d",&id);
    scanf("%d%d",&tree[id].left,&tree[id].right);
    tree[tree[id].left].parent=id;
    tree[tree[id].right].parent=id;
    }
  for(i=0;i<n;i++)
    print(i);

 
  
  return 0;
}

int degree(int i){
  int count=0;
  if(tree[i].left!=null)
    count++;
  if(tree[i].right!=null)
    count++;
  return count;
}

int sibling(int i){
  if(tree[i].parent==null)
    return null;
  else {
    if(tree[tree[i].parent].left==i) return tree[tree[i].parent].right;
    if(tree[tree[i].parent].right==i) return tree[tree[i].parent].left;
  }
}

int depth(int i){
  int dep=0;
  while(tree[i].parent!=null){
    i=tree[i].parent;
    dep++;  
  }
  return dep;
}

int Height(int i){
  int h1=0;
  int h2=0;
  if(tree[i].left!=null) h1=Height(tree[i].left)+1;
  if(tree[i].right!=null) h2=Height(tree[i].right)+1;

  if(h1>h2)height[i]=h1;
  else height[i]=h2;
  return height[i];
}

void print(int i){
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,tree[i].parent,sibling(i),degree(i),depth(i),Height(i));

  if(tree[i].parent==null) printf("root\n");
  else if(tree[i].left==null&&tree[i].right==null) printf("leaf\n");
  else printf("internal node\n");
}
