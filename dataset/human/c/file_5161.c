#include<stdio.h>
#define max 10000
#define nil -1
#define min(x,y) (((x)>(y)) ?(x):(y))

struct node {int parent;int left;int right;};

struct node t[max];
int n,d[max],h[max];

void setdepth(int u,int a){
  if(u==nil) return;
  d[u]=a;
  setdepth(t[u].left,a+1);
  setdepth(t[u].right,a+1);
}

int setheight(int u){
  int h1=0,h2=0;
  if(t[u].left!=nil) h1=setheight(t[u].left)+1;
  if(t[u].right!=nil) h2=setheight(t[u].right)+1;
  return h[u]=min(h1,h2);
}

int getsibling(int u){
  if(t[u].parent==nil) return nil;
  if(t[t[u].parent].left!=u&&t[t[u].parent].left!=nil) return t[t[u].parent].left;
  if(t[t[u].parent].right!=u&&t[t[u].parent].right!=nil) return t[t[u].parent].right;
  return nil;
}

void print(int u){
  printf("node %d: parent = %d, sibling = %d, ",u,t[u].parent,getsibling(u));
  int deg =0;
  if(t[u].left!=nil) deg++;
  if(t[u].right!=nil) deg++;
  printf("degree = %d, depth = %d, height = %d, ",deg,d[u],h[u]);

  if(t[u].parent==nil) printf("root\n");
  else if(t[u].left==nil&&t[u].right==nil) printf("leaf\n");
  else printf("internal node\n");
}

int main(){
  int v,l,r,root=0,i;

  scanf("%d",&n);

  for(i=0;i<n;i++) t[i].parent=nil;
  for(i=0;i<n;i++){
    scanf("%d%d%d",&v,&l,&r);
    t[v].left=l;
    t[v].right=r;
    if(l!=nil) t[l].parent=v;
    if(r!=nil) t[r].parent=v;
  }

  for(i=0;i<n;i++) if(t[i].parent==nil) root=i;

  setdepth(root,0);
  setheight(root);

  for(i=0;i<n;i++) print(i);

  return 0;
}
