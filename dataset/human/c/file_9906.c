#include <stdio.h>
#define NUL -1

typedef struct{
  int parent;
  int left;
  int right;
}Node;
Node N[100000];
int n,D[100000];


void depth(int u,int p)
{
  D[u]=p;

  if(N[u].right!=NUL){depth(N[u].right,p);}

  if(N[u].left!=NUL){depth(N[u].left,p+1);}
}

void print(int u){
  int i,c,k=0;
  printf("node %d: parent = %d, depth = %d,",u,N[u].parent,D[u]);
  if(N[u].parent==NUL)printf(" root, ");
  else if(N[u].left==NUL)printf(" leaf, ");
  else printf(" internal node, ");
  printf("[");

  c=N[u].left;
  while(c!=NUL)
    {
      if(k==0)
	{
	  printf("%d",c);
	  k++;
	}
      else
	{
	  printf(", %d",c);
	}
      c=N[c].right;
    }

  k=0;

printf("]\n");
}

int main(){
  int n,i,j,v,d,c,l,r;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      N[i].parent=NUL;
      N[i].left=NUL;
      N[i].right=NUL;
    }
  
   for(i=0;i<n;i++)
    {
      scanf("%d",&v);
      scanf("%d",&d);
      
      for(j=0;j<d;j++)
	{
	  scanf("%d",&c);
	  if(j==0)N[v].left=c;
	  else N[l].right=c;
	  l=c;
	  N[c].parent=v;
	}
    }
      
  for(i=0;i<n;i++)
    {
      if(N[i].parent==NUL)r=i;
    }

  depth(r,0);
  
  for(i=0;i<n;i++)
    {
      print(i);
    }
  return 0;
}
