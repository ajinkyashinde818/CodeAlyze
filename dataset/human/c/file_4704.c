#include<stdio.h>
#include<stdlib.h>
#define MAX 100000
#define NIL -1

struct Node
{
  int parent;
  int left;
  int right;
};

struct Node T[MAX];
int n, A[MAX], B[MAX];

void setDepth(int u, int d)
{
  if(u == NIL)
    {
      return;
    }
  A[u] = d;
  setDepth(T[u].left, d+1);
  setDepth(T[u].right, d+1);
}

int setHeight(int u)
{
  int a = 0, b = 0;
  if(T[u].left != NIL)
    {
      a = setHeight(T[u].left) + 1;
    }
  if(T[u].right != NIL)
    {
      b = setHeight(T[u].right) + 1;
    }
  return B[u] = (a > b ? a : b);
}

int getSibling(int u)
{
  if(T[u].parent == NIL)
    {
      return NIL;
    }
  if(T[T[u].parent].left != u && T[T[u].parent].left != NIL)
    {
      return T[T[u].parent].left;
    }
  if(T[T[u].parent].right != u && T[T[u].parent].right != NIL)
    {
      return T[T[u].parent].right;
    }
  return NIL;
}

void print(int u)
{
  int i, c, d = 0;
  printf("node %d: ", u);
  printf("parent = %d, ", T[u].parent);
  printf("sibling = %d, ", getSibling(u));
  if(T[u].left != NIL)
    {
      d++;
    }
  if(T[u].right != NIL)
    {
      d++;
    }
  printf("degree = %d, ", d);
  printf("depth = %d, ", A[u]);
  printf("height = %d, ", B[u]);
  if(T[u].parent == NIL)
    {
      printf("root\n");
    }
  else if(T[u].left == NIL && T[u].right == NIL)
    {
      printf("leaf\n");
    }
  else
    {
      printf("internal node\n");
    }
}

int main()
{
  int i, root = 0, a, b, c;

  scanf("%d", &n);
  for(i = 0; i < n; i++)
    {
      T[i].parent = NIL;
    }
  for(i = 0; i < n; i++)
    {
      scanf("%d", &a);
      scanf("%d", &b);
      scanf("%d", &c);
      T[a].left = b;
      T[a].right = c;
      if(b != NIL)
	{
	  T[b].parent = a;
	}
      if(c != NIL)
	{
	  T[c].parent = a;
	}
    }
  for(i = 0; i < n; i++)
    {
      if(T[i].parent == NIL)
	{
	  root = i;
	}
    }

  setDepth(root, 0);
  setHeight(root);
  for(i = 0; i < n; i++)
    {
      print(i);
    }
  return 0;
}
