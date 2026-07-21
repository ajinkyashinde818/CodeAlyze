#include<stdio.h>
#define M 100005
#define NIL -1

typedef struct{
  int p,l,r;
}Node;

Node T[M];
int n, D[M];

void print(int a){
  int i, c;
  printf("node %d: ",a);
  printf("parent = %d, ",T[a].p);
  printf("depth = %d, ",D[a]);

  if(T[a].p==NIL)printf("root, ");
  else if(T[a].l == NIL)printf("leaf, ");
  else printf("internal node, ");

  printf("[");

  for(i = 0,c = T[a].l;c != NIL; i++,c = T[c].r){
    if(i)printf(", ");
    printf("%d",c);
  }
  printf("]\n");
}

void rec(int a,int b)
{
  D[a]=b;
  if(T[a].r != NIL)rec(T[a].r, b);
  if(T[a].l != NIL)rec(T[a].l, b+1);
}

int main()
{
  int i,j,d,v,c,l,r;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      T[i].p = T[i].l = T[i].r = NIL;
    }
  for(i = 0; i < n;i++)
    {
      scanf("%d %d", &v,&d);
      for(j=0; j < d; j++)
	{
	  scanf("%d",&c);
	  if(j==0)T[v].l =c;
	  else T[l].r = c;
	  l=c;
	  T[c].p = v;
	}
    }
  for(i = 0;i < n; i++)
    {
      if(T[i].p == NIL) r = i;
    }

  rec(r,0);

  for(i = 0; i<n;i++) print(i);
  return 0;
}
