#include<stdio.h>

#define N 100000

typedef struct
			  {
			    int parent;
			    int left;
			    int right;
} node;

int finddepth(int);
int findheight(int);

node T[N];

int main()
{
  int pa, x, y, i, j, n, k, c;

  scanf("%d", &n);
  for(i=0; i<n; i++)
    {
      T[i].parent = -1;
      T[i].left = -1;
      T[i].right = -1;
    }
  

  for(i=0; i<n; i++)
    {
      scanf("%d", &pa);

      scanf("%d%d", &x, &y);
        if(x!=-1)T[x].parent = pa;
        if(y!=-1)T[y].parent = pa;
      T[pa].left = x;
      T[pa].right = y;
        
    }
  for(i=0; i<n; i++)
    {
      c=0;
      printf("node %d: parent = %d, ", i, T[i].parent);
      if(T[i].parent == -1)
        {
          printf("sibling = -1, ");
        }
      else if(T[T[i].parent].left == i)
        {
          printf("sibling = %d, ", T[T[i].parent].right);
        }
      else
        {
          printf("sibling = %d, ", T[T[i].parent].left);
        }

      if(T[i].left != -1) c++;
      if(T[i].right != -1) c++;

      printf("degree = %d, depth = %d, height = %d, ", c, finddepth(i), findheight(i));
      
      if(T[i].parent == -1)
        {
          printf("root\n");
        }
      else if(T[i].left != -1 || T[i].right != -1)
        {
          printf("internal node\n");
        }
      else
        {
          printf("leaf\n");
        }
    }
      
  return 0;
}

int finddepth(int x)
{
  int c=0;
  while(T[x].parent >= 0)
    {
      c++;
      x = T[x].parent;
    }
  return c;
}
int findheight(int x)
{
  int l=0, r=0;

  if(T[x].left != -1)
    {
      l = findheight(T[x].left)+1;
    }
  if(T[x].right != -1)
    {
      r = findheight(T[x].right)+1;
    }
  if(l > r)
    {
      return l;
    }
  else
    {
      return r;
    }
}
