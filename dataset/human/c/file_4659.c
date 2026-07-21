#include <stdio.h>
#define N 100000
#define NIL -1
struct Node{
  int parent;
  int right;
  int left;
};
struct Node Tree[N];
int n,D[N];
int getDepth(int a){
  int dep=0;
  while(Tree[a].parent!=-1){
    a=Tree[a].parent;
    dep++;
  }
  return dep;
}
int getsibling(int x){
  if(Tree[x].parent==NIL) return NIL;
  if(Tree[Tree[x].parent].left!=x&&Tree[Tree[x].parent].left!=NIL) return Tree[Tree[x].parent].left;
  if(Tree[Tree[x].parent].right!=x&&Tree[Tree[x].parent].right!=NIL) return Tree[Tree[x].parent].right;
  else return NIL;
}
int getheight(int x){
  int height1=0,height2=0;
  if(Tree[x].left!=NIL) height1=getheight(Tree[x].left)+1;
  if(Tree[x].right!=NIL) height2=getheight(Tree[x].right)+1;
  if(height1>=height2) return height1;
  else return height2;
}
void print(int x){
  int i,j,deg=0;
  if(Tree[x].left!=NIL) deg++;
  if(Tree[x].right!=NIL) deg++;
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",x,Tree[x].parent,getsibling(x),deg,D[x],getheight(x));
  if(Tree[x].parent==NIL) printf("root\n");
  else if(Tree[x].left==NIL&&Tree[x].right==NIL) printf("leaf\n");
  else printf("internal node\n");
}
int main(){
  int a,b,c,i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    Tree[i].parent=NIL;
    Tree[i].left=NIL;
    Tree[i].right=NIL;
  }
  for(i=0;i<n;i++){
    scanf("%d%d%d",&a,&b,&c);
    Tree[a].left=b;
    Tree[a].right=c;
    if(b!=NIL) Tree[b].parent=a;
    if(c!=NIL) Tree[c].parent=a;
  }
  for(i=0;i<n;i++){
    D[i]=getDepth(i);
  }
  for(i=0;i<n;i++){
    print(i);
  }
  return 0;
}
