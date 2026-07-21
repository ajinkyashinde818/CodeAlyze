#include <stdio.h>
#define NUL -1

typedef struct{
  int parent;
  int left;
  int right;
}Node;

Node N[25];
int n,D[25],H[25];


void depth(int u,int p)
{
  if(u==NUL)return;
  D[u]=p;
  depth(N[u].left,p+1);
  depth(N[u].right,p+1);
}

int height(int u)
{
  int a=0;
  int b=0;
  if(N[u].left!=NUL){a = height(N[u].left)+1;}
  if(N[u].right!=NUL){b = height(N[u].right)+1;}

  if(a>b){H[u]=a;return a;}
  else{H[u]=b;return b;}
}

int sibl(int u)
{
  if(N[u].parent == NUL)return NUL;
  if(N[N[u].parent].left!=u&&N[N[u].parent].left!=NUL){return N[N[u].parent].left;}
  if(N[N[u].parent].right!=u&&N[N[u].parent].right!=NUL){return N[N[u].parent].right;}
  return NUL;
}

void print(int u){
  printf("node %d: parent = %d, ",u,N[u].parent);
  printf("sibling = %d, ",sibl(u));
  int k=0;
  if(N[u].left!=NUL)k++;
  if(N[u].right!=NUL)k++;
  printf("degree = %d, ",k);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",H[u]);
  
  if(N[u].parent==NUL)printf("root");
  else if(N[u].left==NUL && N[u].right==NUL)printf("leaf");
  else printf("internal node");
  printf("\n");
}

int main(){
  int i,v,l,r,root=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      N[i].parent=NUL;
    }
  for(i=0;i<n;i++)
    {
      scanf("%d%d%d",&v,&l,&r);
      N[v].left=l;
      N[v].right=r;
      if(l!=NUL)N[l].parent=v;
      if(r!=NUL)N[r].parent=v;      
    }
  for(i=0;i<n;i++)
    {
      if(N[i].parent==NUL)root=i;
    }
  depth(root,0);
  height(root);

  for(i=0;i<n;i++)
    {
      print(i);
    }
  return 0;
}
