#include <stdio.h>
#include <stdlib.h>
#define NMAX 5000
struct node {
  int id;
  struct node *next;
};
struct node *list[NMAX];
void Insert(int a, int b);
int main(void)
{
  int i, n, m, a, b, top = 0, tail = 0, pcheck = 0, squeue[NMAX], wcount[NMAX] = {0};
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) list[i] = NULL;
  for (i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    Insert(a - 1, b - 1);
    wcount[b-1]++;
  }
  for (i = 0; i < n; i++) if (wcount[i] == 0) squeue[tail++] = i;
  while (top < tail) {
    struct node *nd;
    pcheck |= (tail - top) > 1;
    i = squeue[top++];
    printf("%d\n", i + 1);
    for (nd = list[i]; nd != NULL; nd = nd ->next) {
      if (--wcount[nd->id] == 0) squeue[tail++] = nd->id;
    }
  }
  printf("%d\n", pcheck);
  for (i = 0; i < n; i++) free(list[i]);
}

void Insert(int a, int b)
{
  struct node *p = (struct node*)malloc(sizeof(struct node));
  p->id = b;
  p->next = list[a];
  list[a] = p;
}
