#include <stdio.h>
#define MAX 100005
#define NIL -1

struct Node{int p,l,r;};

struct Node T[MAX];
int n,D[MAX];

void print(int u)
{
  int i,c;
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].p);
  printf("depth = %d, ",D[u]);
  if(T[u].p == NIL) printf("root, ");
  else if(T[u].l == NIL) printf("leaf, ");
  else printf("internal node, ");
  printf("[");
  i = 0;
  for(c = T[u].l; c != NIL; c = T[c].r)
    {
      if(i) printf(", ");
      printf("%d",c);
      i++;
    }
  printf("]\n");
};

int rec(int u)
{
  int d;
  d = 0;
  while(T[u].p != NIL)
    {
      u = T[u].p;
      d++;
    }
  return d;
};

int main()
{
  int i,j,d,v,c,l,r;
  
  scanf("%d",&n);
  for(i = 0; i < n; i++)
    {
      T[i].p = NIL;
      T[i].l = NIL;
      T[i].r = NIL;
    }
  
  for(i = 0; i < n; i++)
    {
      scanf("%d %d",&v,&d);
      
      for(j = 0; j < d; j++)
	{
	  scanf("%d",&c);
	  if(!j) T[v].l = c;
	  else T[l].r = c;
	  l = c;
	  T[c].p = v;
	}
    }
  for(i = 0; i < n; i++)
    if(T[i].p == NIL) 
  for(i = 0; i < n; i++)
    D[i]=rec(i);
  for(i = 0; i < n; i++)
    print(i);
  
  return 0;
}
