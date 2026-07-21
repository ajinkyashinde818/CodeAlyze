#include <stdio.h>
struct Node {
  int parent;
  int left;
  int right;
};
int n;
struct Node tree[30];
int dipth[30],height[30];
void getdip(int,int);
int gettree(int);
int getsibling(int);
void printtree(int);
int main(){
  int i,id,left,right,root;
  scanf("%d",&n);
  for(i=0;i<n;i++)tree[i].parent=tree[i].left=tree[i].right=-1;
  for(i=0;i<n;i++){
    scanf("%d %d %d",&id,&left,&right);
    tree[id].left=left;
    tree[id].right=right;
    if(left!=-1)tree[left].parent=id;
    if(right!=-1)tree[right].parent=id;
  }
  for(i=0;i<n;i++){
    if(tree[i].parent==-1)root=i;
  }
  getdip(root,0);
  getheight(root);
  for(i=0;i<n;i++)printtree(i);
  return 0;
}
int getheight(int root){
  int h1=0,h2=0;
  if(tree[root].left!=-1)h1=getheight(tree[root].left)+1;
  if(tree[root].right!=-1)h2=getheight(tree[root].right)+1;
  if(h1>h2)height[root]=h1;
  else height[root]=h2;
  return height[root];
}
int getsibling(int num){
  if(tree[num].parent==-1)return -1;
  if(tree[tree[num].parent].left!=num&&tree[tree[num].parent].left!=-1)return tree[tree[num]\
.parent].left;
  else if(tree[tree[num].parent].right!=num&&tree[tree[num].parent].right!=-1)return tree[tr\
ee[num].parent].right;
  return -1;
}
void getdip(int r,int d){
  if(r==-1)return;
  dipth[r]=d;
  if(tree[r].right!=-1)getdip(tree[r].right,d+1);
  if(tree[r].left!=-1)getdip(tree[r].left,d+1);
}
void printtree(int i){
  int m,j=0,digree=0;
  if(tree[i].right!=-1)digree++;
  if(tree[i].left!=-1)digree++;
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,tree\
[i].parent,getsibling(i),digree,dipth[i],height[i]);
  if(tree[i].parent==-1)printf("root");
  else if(tree[i].left==-1&&tree[i].right==-1)printf("leaf");
  else printf("internal node");
  printf("\n");
}
