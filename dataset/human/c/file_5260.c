#include <stdio.h>

#define NIL -1

struct Node
{
  int p, l, r, s, deg;
};

struct Node T[25];

int Height(int);

int main()
{
  int i, n, node, l, r, dep, h, k;

  scanf("%d",&n);

  for(i = 0; i < n; i++)
    {
      T[i].p = NIL;
      T[i].l = NIL;
      T[i].r = NIL;
      T[i].s = NIL;
      T[i].deg = 0;
    }

  for(i = 0; i < n; i++)
    {
      scanf("%d%d%d",&node,&l,&r);
      if(l != NIL)
	{
	  T[node].l = l;
	  T[l].p = node;
	  T[r].s = l;
	  T[node].deg++;
	}
      if(r != NIL)
	{
	  T[node].r = r;
	  T[r].p = node;
	  T[l].s = r;
	  T[node].deg++;
	}
    }

  for(i = 0; i < n; i++)
    {
      printf("node %d: ",i);
      printf("parent = %d, ",T[i].p);
      printf("sibling = %d, ",T[i].s);
      printf("degree = %d, ",T[i].deg);
      k = i;
      dep = 0;
      while(T[k].p != NIL)
	{
	  k = T[k].p;
	  dep++;
	}
      printf("depth = %d, ",dep);
      h = Height(i);
      printf("height = %d, ",h);
      if(T[i].p == NIL)printf("root");
      else if(T[i].deg == 0)printf("leaf");
      else printf("internal node");
      printf("\n");
    }
  
  return 0;
}

int Height(int x)
{
  int hl = 0, hr = 0;
  
  if(x == NIL)return -1;

  hl = Height(T[x].l);
  hr = Height(T[x].r);

  if(hl > hr)return hl+1;
  else return hr+1;
}
