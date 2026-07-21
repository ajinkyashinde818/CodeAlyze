#include <stdio.h>
#define MAX 100005

int parent[MAX], left[MAX], right[MAX];
int n, D[MAX];

int getDepth(int u)
{
  int d = 0;

  while (parent[u] != -1)
  {
    u = parent[u];
    d++;
  }
  return d;
}

void setDepth(int u, int p)
{
  D[u] = p;
  if (right[u] != -1)
    setDepth(right[u], p);
  if (left[u] != -1)
    setDepth(left[u], p + 1);
}

void printChildren(int u)
{
  int i, c;

  printf("node %d: ", u);
  printf("parent = %d, ", parent[u]);
  printf("depth = %d, ", getDepth(u));

  if (parent[u] == -1)
    printf("root, ");
  else if (left[u] == -1)
    printf("leaf, ");
  else
    printf("internal node, ");
  printf("[");

  for (i = 0, c = left[u]; c != -1; i++, c = right[c])
  {
    if (i)
      printf(", ");
    printf("%d", c);
  }
  printf("]\n");
}

int main()
{
  int i, j, d, v, c, l, r;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    parent[i] = left[i] = right[i] = -1;

  for (i = 0; i < n; i++)
  {
    scanf("%d", &v);
    scanf("%d", &d);
    for (j = 0; j < d; j++)
    {
      scanf("%d", &c);
      if (j == 0)
        left[v] = c;
      else
        right[l] = c;
      l = c;
      parent[c] = v;
    }
  }
  for (i = 0; i < n; i++)
  {
    if (parent[i] == -1)
      r = i;
  }

  setDepth(r, 0);

  for (i = 0; i < n; i++)
    printChildren(i);

  return 0;
}
