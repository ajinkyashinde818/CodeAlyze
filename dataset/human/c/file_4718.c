#include<stdio.h>
#define MAX 10000
#define NIL -1

struct node{int parent,left,right;};

struct node Tree[MAX];
int n,D[MAX],H[MAX];

void print(int);
void Depth(int,int);
int Height(int);
int Sibling(int);


int main()
{
  int i,id,left,right,root=0;
  scanf("%d",&n);

   for(i=0;i<n;i++){
    Tree[i].parent=NIL;}
   
  for(i=0;i<n;i++){
    scanf("%d%d%d",&id,&left,&right);
    Tree[id].left = left;
    Tree[id].right = right;
    if(left != NIL)Tree[left].parent=id;
    if(right != NIL)Tree[right].parent=id;
                  }
  for(i=0;i<n;i++)
    {if(Tree[i].parent==NIL)root=i;  }

  Depth(root,0);
  Height(root);
  
  for(i=0;i<n;i++) print(i);
  return 0;
}

void Depth(int u,int d)
{
  if(u==NIL)return;
  D[u]=d;

  Depth(Tree[u].left,d+1);
  Depth(Tree[u].right,d+1);
}

int Height(int u)
{
  int h1=0,h2=0;
  if(Tree[u].left != NIL)
    h1=Height(Tree[u].left)+1;
  if(Tree[u].right != NIL)
    h2=Height(Tree[u].right)+1;
  if(h1>h2)H[u]=h1;
  else H[u]=h2;

  return H[u];
}

int Sibling(int u)
{
  if(Tree[u].parent == NIL)return NIL;
  if(Tree[Tree[u].parent].left !=u &&Tree[Tree[u].parent].left != NIL)
    return Tree[Tree[u].parent].left;
  if(Tree[Tree[u].parent].right !=u &&Tree[Tree[u].parent].right != NIL)
    return Tree[Tree[u].parent].right;
  return NIL;
}

void print(int u)
{
  printf("node %d: ",u);
  printf("parent = %d, ",Tree[u].parent);
  printf("sibling = %d, ",Sibling(u));
  int deg=0;
  if(Tree[u].left!=NIL)deg++;
  if(Tree[u].right!=NIL)deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",H[u]);

  if(Tree[u].parent==NIL)printf("root\n");
  else if(Tree[u].left == NIL && Tree[u].right == NIL)printf("leaf\n");
  else  printf("internal node\n");
}
