#include<stdio.h>

#define MAX 25
#define NIL -1

typedef struct
{
  int parent;
  int sib;
  int left;
  int right;
}node;

node T[MAX];
int D[MAX],H[MAX];

void depth(int u,int p)
{
  D[u] = p;

  if(T[u].right != NIL) depth(T[u].right,p+1);
  if(T[u].left != NIL) depth(T[u].left,p+1);

  return;
}

void height(int u,int p)
{
  if(T[u].left == NIL && T[u].right == NIL) H[u] = p = 0;
  else if(p > H[u]) H[u] = p;

  if(T[u].left != NIL && H[T[u].left] == NIL) height(T[u].left,0);
  if(T[u].right != NIL && H[T[u].right] == NIL) height(T[u].right,0);
  if(T[u].parent != NIL) height(T[u].parent,p+1);
  
  return;
}

void print(int u)
{
  int deg=0;
  
  printf("node %d: parent = %d, sibling = %d, ",u,T[u].parent,T[u].sib);

  if(T[u].left != NIL) deg++;
  if(T[u].right != NIL) deg++;

  printf("degree = %d, depth = %d, height = %d, ",deg,D[u],H[u]);

  if(T[u].parent == NIL) printf("root\n");
  else  if(T[u].left != NIL || T[u].right != NIL) printf("internal node\n");
  else printf("leaf\n");
  
  return;
}

int main()
{
  int n,i,id,left,right,root,maxdep,min;

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++) //データの初期化
    {
      T[i].parent = NIL;
      T[i].sib = NIL;
      T[i].left = NIL;
      T[i].right = NIL;
      H[i] = NIL;
    }

  for(i = 0 ; i < n ; i++)
    {
      scanf("%d",&id);

      scanf("%d %d",&left,&right);

      T[left].parent = T[right].parent = id;

      T[id].left = T[right].sib = left;
      T[id].right = T[left].sib = right;
    }

  for(i = 0 ; i < n ; i++)
    {
      if(T[i].parent == -1) root = i;
    }

  depth(root,0);

  for(i = 0,maxdep = 0 ; i < n ; i++)
    {
      if(D[i] > maxdep)
	{
	  maxdep = D[i];
	  min = i; 
	}
    }
  
  height(min,0);

  for(i = 0 ; i < n ; i++) print(i);
  
  return 0;
}
