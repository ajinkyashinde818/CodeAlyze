#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#define lpton(i,n) for(int i=0;i<(int)n;i++)
#define lpto0(i,n) for(int i=n;i>-1;i--)
#define lpmn(i,m,n) for(i=m;i<n;i++)
#define ms0(l) memset(l,0,sizeof(l))
#define ms(l,n,s) memset(l,n,s)
#define m(x,n) (x*)malloc(n*sizeof(x))
typedef struct tree{
  int nnode;
  int parent;
  int left;
  int right;
}tree;
int dep;
void print(tree*,int);
int sibling(tree*,int);
int degree(tree*,int);
int depth(tree*,int);
int height(tree*,int);
char* typename(tree*,int);
int main(){
  int n,nnode;
  tree *tr;
  scanf("%d",&n);
  tr=m(tree,n);
  ms(tr,-1,n*sizeof(tree));
  lpton(i,n){
    scanf("%d",&nnode);
    (tr+nnode)->nnode=nnode;
    scanf("%d%d",&(tr+nnode)->left,&(tr+nnode)->right);
    (tr+((tr+nnode)->left))->parent=nnode;
    (tr+((tr+nnode)->right))->parent=nnode;
  }
  print(tr,n);
  free(tr);
  return 0;
}
void print(tree *tr,int n){
int sb,dg,dp,hg;
  lpton(i,n){
    dep=0;
    sb=sibling(tr,i);
    dg=degree(tr,i);
    dp=depth(tr,i);
    hg=height(tr,i);
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n",(tr+i)->nnode,(tr+i)->parent,sb,dg,dp,hg,typename(tr,i));
  }
}
int sibling(tree *tr,int i){
  if((tr+i)->parent==-1)return -1;
  else if((tr+((tr+i)->parent))->left==(tr+i)->nnode)return (tr+((tr+i)->parent))->right;
  else return (tr+((tr+i)->parent))->left;
}
int degree(tree *tr,int i){
  if((tr+i)->right==-1&&(tr+i)->left==-1)return 0;
  else if((tr+i)->right!=-1&&(tr+i)->left!=-1)return 2;
  else return 1;
}
int depth(tree *tr,int i){
  if((tr+i)->parent==-1)return dep;
  depth(tr,(tr+i)->parent);
  return dep+=1;
}
int height(tree *tr,int i){
  int h1=0,h2=0;
  if((tr+i)->left!=-1)h1=(height(tr,(tr+i)->left))+1;
  if((tr+i)->right!=-1)h2=(height(tr,(tr+i)->right))+1;
  return (h1>h2?h1:h2);
}
char *typename(tree *tr,int i){
if((tr+i)->parent==-1)return "root";
else if(degree(tr,i)==0)return "leaf";
else return "internal node";
}
