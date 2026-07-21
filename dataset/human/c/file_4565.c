#include<stdio.h>
#include<stdlib.h>

int calcdep(int);
int tjudge(int);
int calcdeg(int);
int calchei(int);
int greater(int, int);

typedef struct {
  int parent;
  int sibling;
  int left, right;
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
      t[i].sibling = -1;
    }
  
  for(i = 0; i < n; i++)
    {    
      scanf("%d", &id);
    
      scanf("%d %d", &t[id].left, &t[id].right);
      t[t[id].left].parent = id;
      t[t[id].left].sibling = t[id].right;
      t[t[id].right].parent = id;
      t[t[id].right].sibling = t[id].left;
    }
  
  for(i = 0; i < n; i++)
    {
      printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n",
	     i, t[i].parent, t[i].sibling, calcdeg(i), calcdep(i), calchei(i)-1, type[tjudge(i)]);
    }
  
  return 0;
}

int calcdep(int key)
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
  if(t[key].right == -1 && t[key].left == -1)return 2;
  return 1;
}

int calcdeg(int key)
{
  int count = 0;
  
  if(t[key].left != -1)count++;
  if(t[key].right != -1)count++;
  
  return count;
}

int calchei(int key)
{
  if(key == -1)return 0;
  else return greater(calchei(t[key].left), calchei(t[key].right)) + 1;
}

int greater(int x, int y)
{
  if(x > y) return x;
  return y;
}
  
/*  int count;

  if(t[key].left == -1)
    {
      if(t[key].right == -1)
	{
	  return calchei(t[t[key].parent].right);
	}
      count++;
      return calchei(t[key].right);
    }
  count++;
      return calchei(t[key].left);
*/
