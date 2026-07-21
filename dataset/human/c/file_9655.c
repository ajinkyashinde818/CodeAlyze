#include <stdio.h>
#define N 100000
#define NIL -1
int Depth(int );
void display(int );
struct Node {
  int parent;
  int left;
  int right;
};

struct Node T[N];
int n,D[N];

int main()
{
  int a,b,i,j,l,m;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      T[i].parent=NIL;
      T[i].left=NIL;
      T[i].right=NIL;
    }
  
  for(i=0;i<n;i++)
    {
      scanf("%d%d",&l,&m);
      for(j=0;j<m;j++)
	{
	  scanf("%d",&a);
	  if(j==0) T[l].left=a;
	  else T[b].right=a;
	  b=a;
	  T[a].parent=l;
	}
    }
  for(i=0;i<n;i++)
    {
      D[i]=Depth(i);
    }
  for(i=0;i<n;i++)
    {
      display(i);
    }
  return 0;
}

int Depth(int a)
{
  int d=0;
  while(T[a].parent!=-1)
    {
      a=T[a].parent;
      d++;
    }
  return d;
}
void display(int x)
{
  int i,j;
  printf("node %d: parent = %d, depth = %d, ",x,T[x].parent,D[x]);
  if(T[x].parent==-1) printf("root, ");
  else if(T[x].left==-1) printf("leaf, ");
  else printf("internal node, ");

  printf("[");
  for(i=0,j=T[x].left;j!=NIL;i++,j=T[j].right)
    {
      if(i) printf(", ");
      printf("%d",j);
    }
  printf("]\n");
}
