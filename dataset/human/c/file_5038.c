#include <stdio.h>
#define MAX 100000

struct Node{
  int parent,left,right;
};

struct Node T[MAX];
int dep[MAX],h[MAX];

void SetDepth(int u,int d){
  if(u==-1)return;
  dep[u]=d;
  SetDepth(T[u].left,d+1);
  SetDepth(T[u].right,d+1);
}

int SetHeight(int u){
  int h1=0,h2=0;
  if(T[u].left!=-1)h1=SetHeight(T[u].left)+1;
  if(T[u].right!=-1)h2=SetHeight(T[u].right)+1;
  if(h1>h2)return h[u]=h1;
  else return h[u]=h2;
}

int GetSibling(int u){
  if(T[u].parent==-1)return -1;
  if(T[T[u].parent].left!=u && T[T[u].parent].left!=-1)return T[T[u].parent].left;
  if(T[T[u].parent].right!=u && T[T[u].parent].right!=-1)return T[T[u].parent].right;
  return -1;
}

int main(){
  int i,n,id,l,r,root,deg;
  scanf("%d",&n);
  for(i=0;i<n;i++)T[i].parent=-1;

  for(i=0;i<n;i++){
    scanf("%d",&id);
    scanf("%d",&l);
    scanf("%d",&r);
    T[id].left=l;
    T[id].right=r;
    if(l!=-1)T[l].parent=id;
    if(r!=-1)T[r].parent=id;
  }

  for(i=0;i<n;i++){
    if(T[i].parent==-1)root=i;
  }

  SetDepth(root,0);
  SetHeight(root);

  for(i=0;i<n;i++){
    deg=0;
    printf("node %d: ",i);
    printf("parent = %d, ",T[i].parent);
    printf("sibling = %d, ",GetSibling(i));
    if(T[i].left!=-1)deg++;
    if(T[i].right!=-1)deg++;
    printf("degree = %d, ",deg);
    printf("depth = %d, ",dep[i]);
    printf("height = %d, ",h[i]);

    if(T[i].parent==-1)printf("root\n");
    else if(T[i].left==-1 && T[i].right==-1)printf("leaf\n");
    else printf("internal node\n");
  }
  return 0;
}
