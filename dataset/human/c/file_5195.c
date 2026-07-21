#include<stdio.h>
#include<stdlib.h>

#define MAX 100000


struct node {int parent;
             int left;
             int right;
             };

struct node t[MAX];
int n, D[MAX],H[MAX];

void setdepth(int u,int d){
  if(u==-1) return;
  D[u]=d;
  setdepth(t[u].left,d+1);
  setdepth(t[u].right,d+1);
}

int setheight(int u){
  int h1=0,h2=0;
  if(t[u].left!=-1)
    h1=setheight(t[u].left)+1;
  if(t[u].right!=-1)
    h2=setheight(t[u].right)+1;
  return H[u]=(h1>h2?h1:h2);
}

int getsibling(int u){
  if(t[u].parent==-1) return -1;
  if(t[t[u].parent].left!=u&&t[t[u].parent].left!=-1)
    return t[t[u].parent].left;
  if(t[t[u].parent].right != u&&t[t[u].parent].right!=-1)
    return t[t[u].parent].right;
  return -1;
}

void print(int u){
  printf("node %d: ",u);
  printf("parent = %d, ",t[u].parent);
  printf("sibling = %d, ",getsibling(u));
  int deg=0;
  if(t[u].left!=-1) deg++;
  if(t[u].right!=-1) deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",H[u]);

  if(t[u].parent==-1){
    printf("root\n");
  }else if(t[u].left==-1&&t[u].right==-1){
    printf("leaf\n");
  }else{
    printf("internal node\n");
  }
}

int main(){
  int v,l,r,root=0;
  scanf("%d",&n);

  for(int i=0;i<n;i++) t[i].parent=-1;

  for(int i=0;i<n;i++){
    scanf("%d %d %d",&v,&l,&r);
    t[v].left=l;
    t[v].right=r;
    if(l!=-1) t[l].parent=v;
    if(r!=-1) t[r].parent=v;
  }

  for(int i=0;i<n;i++) if(t[i].parent==-1) root=i;
  setdepth(root,0);
  setheight(root);
  for(int i=0;i<n;i++) print(i);

  return 0;
}
