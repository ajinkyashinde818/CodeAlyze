#include<stdio.h>
#include<stdlib.h>
#define NIL -1

typedef struct{
  int right,left;
}Node;

int Depth(int);
int Height(int);

Node node[25];
int n=0;

int main()
{
  int i,j,k=0,l=0,m=0,C=0,c;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      node[i].right=NIL;
      node[i].left=NIL;
    }
  for(i=0;i<n;i++)
    {
      scanf("%d",&m);
      for(j=0;j<2;j++)
        {
          scanf("%d",&C);
          if(j==0)
            {
              k=C;
            }
          else
            {
              node[C].left=k;
              node[k].left=C;
            }
          node[C].right=m;
        }
    }
  for(i=0;i<n;i++)
    {
      c=0;
      printf("node %d: parent = %d, sibling = %d, ",i,node[i].right,node[i].left);
      for(j=0;j<n;j++)
        {
          if(node[j].right==i)
            c++;
        }
      printf("degree = %d, depth = %d, height = %d, ",c,Depth(i),Height(i));
      if(node[i].right==NIL)
        {
          printf("root\n");
        }
      else if(c>0)
        {
          printf("internal node\n");
        }
      else printf("leaf\n");
    }
  return 0;
}

int Depth(int x)
{
  if(node[x].right==NIL)
    {
    return 0;
    }
  else return Depth(node[x].right) + 1;
}

int Height(int y)
{
  int i,a=NIL,b=NIL;
  for(i=0;i<n;i++)
    {
      if(node[i].right==y)
        {
          if(b==NIL)
            b=Height(i);
          else a=Height(i);
        }
    }
  if(a>b)
    {
      return a+1;
    }
  else return b+1;
}
