#include<stdio.h>
#define MAX 100000
#define NOT -1

typedef struct
{
  int parent;
  int left, right;
}Node;

Node Tree[MAX];
int num,Depth[MAX];

void print(int u)
{
  int i,c;
  printf("node %d: ",u);
  printf("parent = %d, ",Tree[u].parent);
  printf("depth = %d, ",Depth[u]);

  if(Tree[u].parent == NOT) printf("root, ");
  else if(Tree[u].left == NOT) printf("leaf, ");
  else printf("internal node, ");

  printf("[");

  for(i=0,c=Tree[u].left;c!= NOT;i++,c=Tree[c].right)
    {
      if(i)printf(", ");
      printf("%d",c);
    }
  printf("]\n");
}

int ans_depth(int u,int par)
{
  Depth[u]=par;
  if(Tree[u].right != NOT) ans_depth(Tree[u].right,par);
  if(Tree[u].left != NOT) ans_depth(Tree[u].left,par+1);
}

int main()
{
  int i,j,dep,adep,c,left,right;
  scanf("%d",&num);
  for(i=0;i<num;i++) Tree[i].parent=Tree[i].left=Tree[i].right=NOT;

  for(i=0;i<num;i++)
    {
      scanf("%d %d",&adep,&dep);
      for(j=0;j<dep;j++)
	{
	  scanf("%d",&c);
	  if(j==0) Tree[adep].left=c;
	  else Tree[left].right=c;
	  left=c;
	  Tree[c].parent=adep;
	}
    }
  for(i=0;i<num;i++)
    {
      if(Tree[i].parent==NOT)right=i;
    }

  ans_depth(right,0);

  for(i=0;i<num;i++)print(i);
  return 0;
}
