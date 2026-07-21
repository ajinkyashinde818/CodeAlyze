#include<stdio.h>
#define MAX 10000
#define NOT -1

typedef struct{
  int parent;
  int left,right;
}Node;

Node Tree[MAX];
int num,Depth[MAX],Height[MAX];
int setHeight(int);
void setDepth(int u, int depth)
{
  if(u==NOT)return;
  Depth[u]=depth;
  setDepth(Tree[u].left,depth+1);
  setDepth(Tree[u].right,depth+1);
}

int setHeight(int u)
{
  int h1=0,h2=0;
  if(Tree[u].left != NOT)
  h1 = setHeight(Tree[u].left)+1;
  if(Tree[u].right != NOT)
  h2 = setHeight(Tree[u].right)+1;
  return Height[u]=(h1>h2 ? h1:h2);
}

int getSibling(int u)
{
  if(Tree[u].parent == NOT) return NOT;
  if(Tree[Tree[u].parent].left != u && Tree[Tree[u].parent].left != NOT)
    return Tree[Tree[u].parent].left;
  if(Tree[Tree[u].parent].right != u && Tree[Tree[u].parent].right != NOT)
    return Tree[Tree[u].parent].right;
  return NOT;
}

void print(int u)
{
  printf("node %d: ",u);
  printf("parent = %d, ",Tree[u].parent);
  printf("sibling = %d, ",getSibling(u));
  int degree =0;
  if(Tree[u].left != NOT) degree++;
  if(Tree[u].right != NOT) degree++;
  printf("degree = %d, ",degree);
  printf("depth = %d, ",Depth[u]);
  printf("height = %d, ",Height[u]);

  if(Tree[u].parent == NOT) printf("root\n");
  else if (Tree[u].left == NOT && Tree[u].right == NOT) printf("leaf\n");
  else printf("internal node\n");
}

int main()
{
  int i;
  int par,left,right,root =0;
  scanf("%d",&num);

  for(i=0; i<num; i++)Tree[i].parent =NOT;

  for(i=0; i<num; i++)
    {
      scanf("%d %d %d",&par,&left,&right);
      Tree[par].left=left;
      Tree[par].right=right;
      if(left != NOT) Tree[left].parent = par;
      if(right != NOT) Tree[right].parent = par;
    }

  for(i=0;i<num;i++)if(Tree[i].parent == NOT)root = i;

  setDepth(root,0);
  setHeight(root);
  for(i=0;i<num;i++) print(i);
  return 0;
}
