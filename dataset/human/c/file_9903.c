#include<stdio.h>
#include<stdlib.h>
#define MAX 100005
#define NIL -1
 
struct Node
{
  int p,l,r;
};
 
struct Node T[MAX];
int n,D[MAX];
 
void print(int v)
{
  int i,c;
  printf("node %d: ",v);
  printf("parent = %d, ",T[v].p);
  printf("depth = %d, ",D[v]);
 
  if( T[v].p == NIL )
    printf("root, ");
  else if( T[v].l == NIL )
    printf("leaf, ");
  else
    printf("internal node, ");
 
  printf("["); 
  for( i = 0, c = T[v].l;c != NIL; i++, c = T[c].r)
    {
      if(i) printf(", ");
      printf("%d",c);
    }
  printf("]\n");
}
 
void rec(int v, int p)
{
  D[v]=p;
  if( T[v].r != NIL)
    rec(T[v].r,p);
  if( T[v].l != NIL )
    rec(T[v].l,p+1);
}
 
 
int main()
{
  int i,j,d,v,c,l,r,n;
 
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      T[i].p=T[i].l=T[i].r=NIL;
    }
 
  for( i = 0; i < n; i++ )
    {
      scanf("%d",&v);
      scanf("%d",&d);
      for( j = 0; j < d; j++ )
	{
	  scanf("%d",&c);
	  if(j==0)T[v].l=c;
	  else T[l].r=c;
	  l=c;
	  T[c].p=v;
	}
    }
  for( i = 0; i < n; i++ )
    {
      if( T[i].p == NIL )
	r=i;
    }
  rec(r,0);
  for( i = 0; i < n; i++ ) 
    print(i);
 
  return 0;
}
