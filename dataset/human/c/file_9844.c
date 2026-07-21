#include<stdio.h>
#include<stdlib.h>

int calcd(int);
int tjudge(int);
  
typedef struct {
  int parent;
  int k;
  int *children;
} Tree;

 Tree *t;

int main()
{
  int i, j;
  int id;
  int n;
  char type[3][15] = {{"root"},{"internal node"},{"leaf"}};

  scanf("%d", &n);

  t = malloc(sizeof(Tree) * n);

   for(i = 0; i < n; i++)
    {
      t[i].parent = -1;
    }
  
  for(i = 0; i < n; i++)
    {    
      scanf("%d", &id);
      
      scanf("%d", &t[id].k);
      t[id].children = malloc(sizeof(int) * t[id].k);
      
      for(j = 0; j < t[id].k; j++)
	{
	  scanf("%d", &t[id].children[j]);
	  t[t[id].children[j]].parent = id;
	}
    }
  for(i = 0; i < n; i++)
    {
      printf("node %d: parent = %d, depth = %d, %s,", i, t[i].parent, calcd(i), type[tjudge(i)]);

      printf(" [");
      if(t[i].k != 0)
	{
	  for(j = 0; j < t[i].k-1; j++)
	    {
	      printf("%d, ",t[i].children[j]);
	    }
	  printf("%d",t[i].children[j]);
	}
      printf("]\n");
    }

  return 0;
}

int calcd(int key)
{
  int count = 0;
  
  while(t[key].parent != -1)
    {
      key = t[key].parent;
      count++;
    }

  return count;
}

int tjudge(int key)
{
  if(t[key].parent == -1)return 0;
  if(t[key].k == 0)return 2;
  return 1;
}
