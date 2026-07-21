#include <stdio.h>
#define MAX 10000
#define NIL -1

struct NODE{
  int p,left,right;
};
struct NODE Tree[MAX];
int n,Depth[MAX],Height[MAX];

void makedepth(int,int);
int makeheight(int);
int makesibling(int);
int main(){
  int i,j,v,l,r,deg,root=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    Tree[i].p=NIL;
  }
  for(i=0;i<n;i++){
    scanf("%d%d%d",&v,&l,&r); 
    Tree[v].left=l;
    Tree[v].right=r;
    if(l!=NIL)Tree[l].p=v;
    if(r!=NIL)Tree[r].p=v;
  }
  for(i=0;i<n;i++){
    if(Tree[i].p==NIL)root=i;
  }
  makedepth(root,0);
  makeheight(root);
  for(i=0;i<n;i++){
    printf("node %d: ",i);
    printf("parent = %d, ",Tree[i].p);
    printf("sibling = %d, ",makesibling(i));
    deg=0;
    if(Tree[i].left!=NIL)deg++;
    if(Tree[i].right!=NIL)deg++;
    printf("degree = %d, ",deg);
    printf("depth = %d, ",Depth[i]);
    printf("height = %d, ",Height[i]);
    if(Tree[i].p==NIL)printf("root\n");
    else if(Tree[i].left==NIL&&Tree[i].right==NIL)printf("leaf\n");
    else printf("internal node\n");
  }
  return 0;
}
void makedepth(int i,int d){
  if(i==NIL)return;
  Depth[i]=d;
  makedepth(Tree[i].left,d+1);
  makedepth(Tree[i].right,d+1);
}
int makeheight(int i){
  int h1=0,h2=0;
  if(Tree[i].left!=NIL) h1=makeheight(Tree[i].left)+1;
  if(Tree[i].right!=NIL) h2=makeheight(Tree[i].right)+1;
  return Height[i] = (h1>h2?h1:h2);
}
  
int makesibling(int i){
  if(Tree[i].p==NIL)return NIL;
  if(Tree[Tree[i].p].left!=i && Tree[Tree[i].p].left!=NIL)return Tree[Tree[i].p].left;
  if(Tree[Tree[i].p].right!=i && Tree[Tree[i].p].right!=NIL)return Tree[Tree[i].p].right;
  return NIL;
}
