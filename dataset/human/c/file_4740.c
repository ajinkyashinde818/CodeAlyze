#include <stdio.h>
#define NIL -1
#define MAX 25

typedef struct{
  int parent,left,right;
} Node;
Node Tree[MAX];
int kazu,Depth[MAX],Height[MAX];

int setHeight(int u){
  int h1,h2;
  h1=h2=0;
  if(Tree[u].right!=NIL) h1=setHeight(Tree[u].right)+1;
  if(Tree[u].left!=NIL) h2=setHeight(Tree[u].left)+1;
  if(h1>h2) return Height[u]=h1;
  else return Height[u]=h2;
}
void setDepth(int u,int depth){
  if(u==NIL) return;
  Depth[u]=depth;
  if(Tree[u].right!=NIL) setDepth(Tree[u].right,depth+1);
  if(Tree[u].left!=NIL) setDepth(Tree[u].left,depth+1);
}
int getSibling(int u){
  if(Tree[u].parent==NIL) return NIL;
  else if(Tree[Tree[u].parent].left==NIL || Tree[Tree[u].parent].right==NIL)
    return NIL;
  else if(Tree[Tree[u].parent].left==u) return Tree[Tree[u].parent].right;
  else return Tree[Tree[u].parent].left;
}


int main(){
  int root,id,i,r,l,degree[MAX];
  char typ[MAX][15];
  scanf("%d",&kazu);
  for(i=0;i<kazu;i++)Tree[i].parent=Tree[i].left=Tree[i].right=NIL;
  for(i=0;i<kazu;i++){
    scanf("%d%d%d",&id,&r,&l);
    if(r==-1&&l==-1) degree[id]=0;
    else if(r==-1 || l==-1) degree[id]=1;
    else degree[id]=2;
    Tree[r].parent=id;
    Tree[l].parent=id;
    Tree[id].right=r;
    Tree[id].left=l;
  }
  for(i=0;i<kazu;i++) if(Tree[i].parent==NIL) root=i;
  setDepth(root,0);
  setHeight(root);
  for(i=0;i<kazu;i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d,",i,Tree[i].parent,getSibling(i),degree[i],Depth[i],Height[i]);
    if (Depth[i]==0) printf(" root\n");
    else if(Height[i]==0) printf(" leaf\n");
    else printf(" internal node\n");
  }
  return 0;
}
