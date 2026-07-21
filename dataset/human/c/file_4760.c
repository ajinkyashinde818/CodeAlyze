#include <stdio.h>
#include <string.h>
typedef struct A{
  int n, right,left,d,parent,depth,height,sibling,degree;
}Node;
Node node[30];
int i,j,N,right,left,n;
int B(int p,int d){
  int a,b;
  if(p==-1)return -1;
  node[p].depth=d;
  a=B(node[p].right,d+1);
  b=B(node[p].left,d+1);
  if(a==-1 && b== -1)node[p].height=0;
  else node[p].height=(a>b?a:b)+1;
  return node[p].height;
}
int main() {
  memset(node,-1,sizeof(node));
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d%d%d",&n,&left,&right);
    node[n].left=left;
    node[n].right=right;
    node[n].degree=(right!=-1)+(left!=-1);
    node[left].sibling=right;
    node[right].sibling=left;
    if(left!=-1)node[left].parent=n;
    if(right!=-1)node[right].parent=n;
  }
  for(i=0;i<N;i++)if(node[i].parent==-1)B(i,0);
  for(i=0;i<N;i++)printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n",i,node[i].parent,node[i].sibling,node[i].degree,node[i].depth,node[i].height,node[i].parent==-1?"root":node[i].left==-1&&node[i].right==-1?"leaf":"internal node");
  return 0;
}
