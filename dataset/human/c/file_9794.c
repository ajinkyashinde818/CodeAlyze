#include<stdio.h>
#define MAX 100005
#define NIL -1

struct Node{int p,l,r;};
struct Node T[MAX];

int n,H,D[MAX];

int getDepth(int u)
{
  int d=0;
  while(T[u].p != NIL)
    {
      u = T[u].p;
      d++;
    }
  return d;
}


void print(int u)
{
  int i,c;

  printf("node %d:",u);
  printf(" ");
  printf("parent = %d,",T[u].p);
  printf(" ");
  printf("depth = %d,",D[u]);
  printf(" ");

  if(T[u].p == NIL)
    {
      printf("root,");
      printf(" ");
    }
  else if(T[u].l == NIL)
    {
      printf("leaf,");
      printf(" ");
    }
  else
    {
      printf("internal node,");
      printf(" ");
    }
  printf("[");

  for(i=0,c=T[u].l;c!=NIL;i++,c=T[c].r)
    {
      if(i) printf(", ");
      printf("%d",c);
    }

  printf("]\n");
}



int main()
{
  int i,j,d,v,c,l;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      T[i].p = T[i].l = T[i].r =NIL;
    }

  for(i=0;i<n;i++)
    {
      scanf("%d%d",&v,&d);
      for(j=0;j<d;j++)
	{
	  scanf("%d",&c);
	  if(j==0) T[v].l=c;
	  else T[l].r =c;
	  l=c;
	  T[c].p =v;
	}
    }

  H=0;
  for(i=0;i<n;i++)
    {
      D[i]=getDepth(i);
      if(D[i]>H)H=D[i];
    }

  for(i=0;i<n;i++) print(i);
  return 0;
}
