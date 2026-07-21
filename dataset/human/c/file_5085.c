#include <stdio.h>
#include <stdlib.h>
#define MAX 100005
#define NIL -1

typedef struct _n {
  int deg;
  int right;
  int left;
  int r;
  int parent;
  int sib;
  int depth;
  int height;
} node;

node tree[MAX];
int n;
void calcDepth(int r) {
  if(tree[r].right !=NIL){
    tree[tree[r].right].depth+=1+tree[r].depth;
  calcDepth(tree[r].right);
  }
  if(tree[r].left != -1){
    tree[tree[r].left].depth+=1+tree[r].depth;
  calcDepth(tree[r].left);
  }
}
int calcHeight(int a) {
  int i,h=0,l,r,n;
  if(tree[a].deg == 0) {
    tree[a].height = 0;
    return 0;
  }
  if(tree[a].left!=NIL)l=calcHeight(tree[a].left);
  else l=0;
  if(tree[a].right!=NIL)r=calcHeight(tree[a].right);
  else r=0;
  if(l<r)h=r;
  else h=l;
  tree[a].height=h+1;
  return h+1;
}
int main() {
  int i,j,k,l,r;
  scanf("%d", &n);
  for(i=0;i<n;i++){
    tree[i].parent=NIL;
    tree[i].sib=NIL;
    tree[i].depth=0;
    tree[i].height=0;
    tree[i].deg=0;
  }
  for(k=0;k<n;k++) {
    scanf("%d",&i);
    scanf("%d %d",&tree[i].left,&tree[i].right);
    if(tree[i].left!=NIL){
      tree[tree[i].left].sib=tree[i].right;
    tree[tree[i].left].parent=i;
    tree[i].deg++;
  }
    if(tree[i].right!=NIL){
      tree[tree[i].right].sib=tree[i].left;
   tree[tree[i].right].parent=i;
   tree[i].deg++;
  }
  }
  for(i=0;i<n;i++) {
    if(tree[i].parent==NIL) k=i;
  }
  calcDepth(k);
  calcHeight(k);
  for(i=0;i<n;i++) {
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,tree[i].parent,tree[i].sib,tree[i].deg,tree[i].depth,tree[i].height);
    if(tree[i].parent==NIL) {
      printf("root\n");
    }
    else if(tree[i].deg==0) {
      printf("leaf\n");
    }
    else{
      printf("internal node\n");
    }
  }
  return 0;
}
