#include<stdio.h>
struct Node
{
  int p;
  int l;
  int r;
};

struct Node T[100000];

int depth(int id)
{
  int dep=0;
  while(T[id].p!=-1)
    {
      dep++;
      id=T[id].p;
    }
  return dep;
}


int sibling(int id)
{
  if(T[id].p==-1) return -1;
  if(T[T[id].p].r==id) return T[T[id].p].l;
  if(T[T[id].p].l==id) return T[T[id].p].r;
}

int degree(int id)
{
  int deg=0;
  if(T[id].l!=-1) deg++;
  if(T[id].r!=-1) deg++;
  return deg;
}

int height(int id)
{
  int lheight=0;
  int rheight=0;

  if(T[id].l!=-1) lheight=height(T[id].l)+1;
  if(T[id].r!=-1) rheight=height(T[id].r)+1;
  if(lheight>rheight) return lheight;
  else return rheight;
}

main()
{
  int n,i,id;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
      T[i].p=T[i].l=T[i].r=-1;
    }

  for(i=0;i<n;i++)
    {
      scanf("%d",&id);
      scanf("%d %d",&T[id].l,&T[id].r);
      T[T[id].l].p=id;
      T[T[id].r].p=id;
    }

  for(i=0;i<n;i++)
    {
      printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,T[i].p,sibling(i),degree(i),depth(i),height(i));

      if(T[i].p==-1)
	{ 
	  printf("root\n");
	}
      else if(T[i].l==-1&&T[i].r==-1)
	{
	  printf("leaf\n");
	}
      else printf("internal node\n");
    }
  return 0;
}
