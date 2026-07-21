#include <stdio.h>
#define MAX 10000
#define NIL -1

typedef struct{
  int parent,left,right;
}tree;

tree T[MAX];
int n,D[MAX],H[MAX];

int getSibling(int);
int setDepth(int,int);
int high(int);
void print(int);

int main()
{
  int v,l,r,i,root=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      T[i].parent=T[i].left=T[i].right=NIL;
    }
  for(i=0;i<n;i++)
    {
      scanf("%d%d%d",&v,&l,&r);
      T[v].left=l;
      T[v].right=r;
      T[l].parent=v;
      T[r].parent=v;
    }
  for(i=0;i<n;i++)
     {
       if(T[i].parent == NIL)
	 r = i;
     }
  setDepth(r,0);
  high(r);
  for(i=0;i<n;i++)
    {
      print(i);
    }
}
void print(int u)
{
  int deg=0;
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].parent);
  printf("sibling = %d, ",getSibling(u));
  if(T[u].left != NIL)
    deg++;
  if(T[u].right != NIL)
    deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",H[u]);
  if(T[u].parent == NIL)
    printf("root\n");
  else if(T[u].left == NIL && T[u].right == NIL)
    printf("leaf\n");
  else
    printf("internal node\n");
}

int setDepth(int u,int d)
{
  if(u == NIL)
    return 0;
  D[u]=d;
  if(T[u].right != NIL)
    setDepth(T[u].right,d+1);
  if(T[u].left != NIL)
    setDepth(T[u].left,d+1);
}

int high(int u)
{
 int h1 = 0,h2 = 0;
 if(T[u].left != NIL)
 h1 = high(T[u].left) + 1;
 if(T[u].right != NIL)
 h2 = high(T[u].right) + 1;
 if(h1 > h2)
 return H[u]=h1;
 else
 return H[u]=h2;
}

int getSibling(int u)
{
  int k;
  if(T[u].parent==NIL)
    return -1;
  k=T[u].parent;
  if(T[k].left == u)
    return T[k].right;
  else
    return T[k].left;
}
