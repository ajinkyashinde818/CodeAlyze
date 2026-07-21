#include<stdio.h>
#define MAX 10000
#define NIL -1

void setDepth(int,int);
int setHeight(int);
int getSebling(int);
void print(int);

typedef struct{
  int parent;
  int left;
  int right;
}node;

node t[MAX];
int n,d[10000],h[10000];

int main(){
  int i,id,l,r,root=0;
  
  scanf("%d",&n);

  for(i=0;i<=n-1;i++){
    t[i].parent=NIL;
  }

  for(i=0;i<=n-1;i++){
    scanf("%d%d%d",&id,&l,&r);
    t[id].left=l;
    t[id].right=r;
    if(l!=NIL)t[l].parent=id;
    if(r!=NIL)t[r].parent=id;
  }

  for(i=0;i<=n-1;i++){
    if(t[i].parent==NIL)root=i;
  }

  setDepth(root,0);
  setHeight(root);

  for(i=0;i<=n-1;i++){
    print(i);
  }
  return 0;
}


void setDepth(int u,int p){
  d[u]=p;
  if(t[u].left!=NIL)setDepth(t[u].left,p+1);
  if(t[u].right!=NIL)setDepth(t[u].right,p+1);
}


int setHeight(int u){
  int h1,h2;
  h1=h2=0;
  if(t[u].left!=NIL)h1=setHeight(t[u].left)+1;
  if(t[u].right!=NIL)h2=setHeight(t[u].right)+1;
  return h[u]=(h1>h2 ? h1:h2);
}


int getSebling(int u){
  if(t[u].parent==NIL)return NIL;
  if(t[t[u].parent].left!=u&&t[t[u].parent].left!=NIL)
    return t[t[u].parent].left;
  if(t[t[u].parent].right!=u&&t[t[u].parent].right!=NIL)
    return t[t[u].parent].right;
  return NIL;
}


void print(int u){
  int deg=0;
  
  printf("node %d: ",u);
  printf("parent = %d, ",t[u].parent);
  printf("sibling = %d, ",getSebling(u));
  if(t[u].left!=NIL)deg++;
  if(t[u].right!=NIL)deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",d[u]);
  printf("height = %d, ",h[u]);
  if(t[u].parent==NIL)printf("root\n");
  else if(t[u].left==NIL && t[u].right==NIL)printf("leaf\n");
  else printf("internal node\n");
}
