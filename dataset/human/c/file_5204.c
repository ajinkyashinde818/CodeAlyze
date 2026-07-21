#include <stdio.h>
#include <stdlib.h>

void hukasa(int,int);
int takasa(int);

typedef struct node{
  int pa;
  int le;
  int ri;
}TREE;

TREE tree[26];
int n,depth[26],sib[26],height[26];

int main(){
  int i,j,node,left,right,degree[26],root,numchild;
  scanf("%d",&n);
  if(n>25) exit(2);
  for(i=0;i<n;i++) {
    tree[i].pa=tree[i].le=tree[i].ri=-1;
    sib[i]=-1;
    degree[i]=0;
  }
  for(i=0;i<n;i++){
    scanf("%d %d %d",&node,&left,&right);
    if(left != -1){
      tree[left].pa=node;
      tree[node].le=left;
      degree[node]++;
    }
    if(right != -1){
      tree[right].pa=node;
      tree[node].ri=right;
      degree[node]++;
    }
    if(left != -1 && right != -1){
      sib[left]=right;
      sib[right]=left;
    }
  }
  for(i=0;i<n;i++){
    if(tree[i].pa==-1) root=i;
  }

  hukasa(root,0);
  takasa(root);
  
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,tree[i].pa,sib[i],degree[i],depth[i],height[i]);
    if(tree[i].pa == -1) printf("root");
    else if(tree[i].le != -1 || tree[i].ri != -1)printf("internal node");
    else printf("leaf");
    printf("\n");
  }
  return 0;
}

void hukasa(int u,int p){
  if(u == -1) return;
  depth[u]=p;
  hukasa(tree[u].ri,p+1);
  hukasa(tree[u].le,p+1);
}

int takasa(int u){
  int h1=0,h2=0;
  if(tree[u].le != -1) h1=takasa(tree[u].le)+1;
  if(tree[u].ri != -1) h2=takasa(tree[u].ri)+1;
  if(h1>h2) return height[u]=h1;
  else return height[u]=h2;
}
