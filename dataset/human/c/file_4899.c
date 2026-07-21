#include<stdio.h>

#define MAX 10000
#define NIL -1

void setDepth(int u,int d);
int setHeight(int u);
int getSibling(int u);
void print(int u);


typedef struct
{
  int parent;
  int left,right;
} Node;

Node T[MAX];
int n;
int D[MAX],H[MAX];

int main(void){

  int l,r,v;
  int root=0;
  int i;
  
  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
      T[i].parent=NIL;
    }
  
  for(i=0;i<n;i++)
    {
      scanf("%d %d %d",&v,&l,&r);
    
      T[v].left=l;
      T[v].right=r;
      
      if(l!=NIL)
	{
	  T[l].parent=v;
	}
    
      if(r!=NIL)
	{
	  T[r].parent=v;
	}
    
    }
  
  for(i=0;i<n;i++)
    {
      if(T[i].parent==NIL)
	{
	  root=i;

	}
    }

  setDepth(root,0);
  setHeight(root);

  for(i=0;i<n;i++)
    {
      print(i);
    }

  return 0;
}

void setDepth(int u,int d)
{
  if(u==NIL)
    return;
  
  D[u]=d;

  setDepth(T[u].left,d+1);
  setDepth(T[u].right,d+1);
}

int setHeight(int u)
{
  int h1=0;
  int h2=0;

  if(T[u].left!=NIL)
    {
      h1=setHeight(T[u].left)+1;
    }
  
  if(T[u].right!=NIL)
    {
      h2=setHeight(T[u].right)+1;
    }

  return H[u]=h1>h2?h1:h2;

}

int getSibling(int u)
{
  if(T[u].parent==NIL)
    {
    return NIL;
    }
  
  if(T[T[u].parent].left!=NIL&&T[T[u].parent].left!=u)
    {
      return T[T[u].parent].left;
    }
  
  if(T[T[u].parent].right!=NIL&&T[T[u].parent].right!=u)
    {
      return T[T[u].parent].right;
    }
  
  return NIL;
}

void print(int u)
{
  int deg=0;
  
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].parent);
  printf("sibling = %d, ",getSibling(u));

  if(T[u].left!=NIL)
    {
      deg++;
    }
  
  if(T[u].right != NIL)
    {
      deg++;
    }
  
  printf("degree = %d, ",deg);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",H[u]);

  if(T[u].parent==NIL)
    {
      puts("root");
    }
  
  else if(T[u].right==NIL&&T[u].left==NIL)
    {
      puts("leaf");
    }
  
  else
    {
      puts("internal node");
    }
  
}
