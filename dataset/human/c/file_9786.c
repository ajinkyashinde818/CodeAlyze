#include <stdio.h>
typedef struct {
  int p,l,r; /* parent,left child,right sibling */
} Node;
Node T[100000];
int depth(int);
int PrintChild(int);
void Print(int);
int main()
{
  int n,i,j,c,id,k,pre;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      T[i].p = T[i].l = T[i].r = -1;
    }
  for(i=0;i<n;i++)
    {
      scanf("%d %d",&id,&k);
      for(j=0;j<k;j++)
	{
	  scanf("%d",&c);
	  T[c].p=id;
	  if(j==0) T[id].l = c;
	  else T[pre].r = c;
	  pre = c;
	}
    }
  for(i=0;i<n;i++)
    {
      Print(i);
    }
  return 0;
}
void Print(int id)
{
  int i;
  printf("node %d: parent = %d, depth = %d, ",id,T[id].p,depth(id));
  if(T[id].p == -1) printf("root, [");
  else if(T[id].l == -1) printf("leaf, [");
  else printf("internal node, [");
  PrintChild(T[id].l);
  printf("]\n");
}
int PrintChild(int id)
{
  if(id == -1) return 0;
  if(T[id].r == -1)printf("%d",id);
  else 
    {
      printf("%d, ",id);
      PrintChild(T[id].r);
    }
  return 0;
}
int depth(int id)
{
  if(T[id].p == -1) return 0;
  return 1+depth(T[id].p);
}
