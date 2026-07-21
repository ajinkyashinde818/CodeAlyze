#include<stdio.h>
#define M 10000
#define NIL -1

typedef struct{
  int parent,left,right;
}Node;

Node T[M];
int n,D[M], H[M];

void setDepth(int a,int b){
  if(a == NIL)return;
  D[a] = b;
  setDepth(T[a].left,b+1);
  setDepth(T[a].right,b+1);
}

int setHeight(int a){
  int h1 = 0;
  int h2 = 0;
  if(T[a].left != NIL)
    h1 = setHeight(T[a].left)+1;
  if(T[a].right != NIL)
    h2 = setHeight(T[a].right)+1;
  if(h1>h2)
    {
      H[a]=h1;
    }
  else
    {
      H[a]= h2;
    }
  return H[a];
}
int gSibling(int s)
{
  if(T[s].parent == NIL)return NIL;
  if(T[T[s].parent].left != s && T[T[s].parent].left != NIL)
    return T[T[s].parent].left;
  if(T[T[s].parent].right != s && T[T[s].parent].right != NIL)
    return T[T[s].parent].right;

  return NIL;
}
int main()
{
  int i,j,v,l,r,deg,root = 0;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
      T[i].parent = NIL;
    }
  for(i = 0;i<n;i++)
    {
      scanf("%d %d %d",&v,&l,&r);
      T[v].left = l;
      T[v].right = r;
      if(l != NIL)T[l].parent = v;
      if(r != NIL)T[r].parent = v;
    }

  for(i = 0;i<n;i++)
    {
      if(T[i].parent == NIL)root = i;
    }

  setDepth(root, 0);
  setHeight(root);

  for(i = 0;i<n;i++)
    {
      printf("node %d: ", i);
      printf("parent = %d, ", T[i].parent);
      printf("sibling = %d, ",gSibling(i));
      deg = 0;
      if(T[i].left != NIL)deg++;
      if(T[i].right != NIL)deg++;
      printf("degree = %d, ",deg);
      printf("depth = %d, ",D[i]);
      printf("height = %d, ",H[i]);

      if(T[i].parent == NIL){
	printf("root\n");
      }
      else if(T[i].left == NIL && T[i].right == NIL)
	{
	  printf("leaf\n");
	}
      else 
	{
	  printf("internal node\n");
	}
    }
  return 0;
}
