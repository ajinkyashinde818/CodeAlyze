#include<stdio.h>
#define MAX 100000
#define NIL -1
struct Node {int p, l, r;};
struct Node T[MAX];
int getDepth(int ,int );
void print(int );
int n,D[MAX];

int main()
{
  int i,j,d,v,c,l,r;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
      T[i].p=NIL;
      T[i].l=NIL;
      T[i].r=NIL;
    }

  for(i=0;i<n;i++)
    {
      scanf("%d %d",&v,&d);
      
      for(j=0;j<d;j++)
	{
	  scanf("%d",&c);
	  if(j==0)T[v].l=c;
	  else T[l].r=c;
	  l=c;
	  T[c].p=v;
	}
    }
  for(i=0;i<n;i++)
    {
      if(T[i].p==NIL)r=i;
    }
  getDepth(r,0);

  
  for(i=0;i<n;i++)print(i);
  return 0;
}


int getDepth(int u,int p)
{
  D[u]=p;
  if(T[u].r!=NIL)getDepth(T[u].r,p);
  if(T[u].l!=NIL)getDepth(T[u].l,p+1);
}

void print(int u)
{
  int i,c;
  printf("node %d: ",u);
  printf("parent = %d,",T[u].p);
  printf(" depth = %d,",D[u]);

  if(T[u].p==NIL)printf(" root, ");
  else if(T[u].l==NIL)printf(" leaf, ");
  else printf(" internal node, ");

  printf("[");
  for(i=0,c=T[u].l;c!=NIL;i++,c=T[c].r)
    {
      if(i)printf(", ");
      printf("%d",c);
    }
  printf("]\n");
}
