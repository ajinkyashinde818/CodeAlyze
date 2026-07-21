#include<stdio.h>

#define MAX 10000
#define NIL -1

void setDepth(int,int);
int Height(int);
int getSibling(int);
void print (int);

typedef struct{
  int parent;
  int left;
  int right;
}node;

node t[MAX];
int n,D[MAX],H[MAX];

int main(){
  int i,v,l,r,root=0;

  scanf("%d",&n);

  for(i=0;i<=n-1;i++){
    t[i].parent=NIL;
  }

  for(i=0;i<=n-1;i++){
    scanf("%d %d %d",&v,&l,&r);

    t[v].left=l;
    t[v].right=r;

    if(l!=NIL) t[l].parent=v;
    if(r!=NIL) t[r].parent=v;
  }

  for(i=0;i<=n-1;i++){
    if(t[i].parent==NIL) root=i;
  }

  setDepth(root,0);
  Height(root);

  for(i=0;i<=n-1;i++){
    print(i);
  }

  return 0;
}

void setDepth(int u,int d){
  
  if(u==NIL) return;
  
  D[u]=d;
  setDepth(t[u].left,d+1);
  setDepth(t[u].right,d+1);
}

int Height(int u){
  int h1=0,h2=0;

  if(t[u].left!=NIL) h1=Height(t[u].left)+1;
  if(t[u].right!=NIL) h2=Height(t[u].right)+1;

  if(h1<h2) return H[u]=h2;
  return H[u]=h1;
}

int getSibling(int u){

  if(t[u].parent==NIL) return NIL;

  if(t[t[u].parent].left!=u && t[t[u].parent].left!=NIL)
    return t[t[u].parent].left;

  if(t[t[u].parent].right!=u && t[t[u].parent].right!=NIL)
    return t[t[u].parent].right;

  return NIL;
}

void print(int u){
  int cnt=0;
  
  printf("node %d: ",u);
  printf("parent = %d, ",t[u].parent);
  printf("sibling = %d, ",getSibling(u));

  if(t[u].left!=NIL) cnt++;
  if(t[u].right!=NIL) cnt++;

  printf("degree = %d, ",cnt);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",H[u]);

  if(t[u].parent==NIL) printf("root\n");
  else if(t[u].left==NIL && t[u].right==NIL) printf("leaf\n");
  else printf("internal node\n");
}
