#include<stdio.h>
#include<string.h>

#define MAX 100005

typedef struct{
  int parent;
  int left;
  int right;
}Roll;

int max(int h1,int h2){
  if(h1>h2)return h1;
  else return h2;
}

int Depth(int root,int d,int *Dep,Roll *Tree){
  if(root==-1)return -1;
  Dep[root]=d;
  Depth(Tree[root].left,d+1,Dep,Tree);
  Depth(Tree[root].right,d+1,Dep,Tree);
  return 0;
}

int Height(int root,Roll *Tree,int *Hei){
  int h1=0,h2=0;
  if(Tree[root].left!=-1)
    h1=Height(Tree[root].left,Tree,Hei)+1;
  if(Tree[root].right!=-1)
    h2=Height(Tree[root].right,Tree,Hei)+1;

    return Hei[root]=max(h1,h2);
}
 
int sibl(int root,Roll *Tree){
  if(Tree[root].parent==-1)return -1;
  if(Tree[Tree[root].parent].left!=root&&Tree[Tree[root].parent].left!=-1)return Tree[Tree[root].parent].left;
  if(Tree[Tree[root].parent].right!=root&&Tree[Tree[root].parent].right!=-1)return Tree[Tree[root].parent].right;
  return -1;
}

void print(int root,Roll *Tree,int *Hei,int *Dep){ 
  printf("node %d: ",root);
  printf("parent = %d, ",Tree[root].parent);
  printf("sibling = %d, ",sibl(root,Tree));
  int deg=0;
  if(Tree[root].left!=-1)deg++;
  if(Tree[root].right!=-1)deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",Dep[root]);
  printf("height = %d, ",Hei[root]);
  if(Tree[root].parent==-1)printf("root");
  else if(Tree[root].left==-1&&Tree[root].right==-1)printf("leaf");
  else printf("internal node");
  printf("\n");
}


int main(){
  Roll Tree[MAX];
  int Dep[MAX],Hei[MAX];
  int id,left,right,root = 0;
  int i,n;
  scanf("%d",&n);
  for(i=0;i<n;i++) Tree[i].parent=-1;
  for(i=0;i<n;i++){
    scanf("%d%d%d",&id,&left,&right);
    Tree[id].left=left;
    Tree[id].right=right;
    if(left!=-1)Tree[left].parent=id;
    if(right!=-1)Tree[right].parent=id;
  }
  for(i=0;i<n;i++)
    if(Tree[i].parent==-1)
      root=i;
  Depth(root,0,Dep,Tree);
  Height(root,Tree,Hei);
  for(i=0;i<n;i++)
    print(i,Tree,Hei,Dep);
  return 0;
}
