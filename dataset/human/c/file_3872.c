#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) > (b) ? (b) : (a))
#define abs(x) ((x) > 0 ? (x) : -(x))
#define MOD (ll)1000000007 //10^9 + 7
#define endl printf("\n")
typedef long long ll;
#define MAX_N (1 << 17)

typedef struct {
  int number;
  int road;
  int railway;
} city;

int
city_comp(const void *a, const void *b)
{
  city *x, *y;
  x = (city *)a; y = (city *)b;
  if (x->road > y->road) return  1;
  if (x->road < y->road) return -1;
  if (x->railway > y->railway) return  1;
  if (x->railway < y->railway) return -1;
  return 0;
}

int get_root(int i, int *root) {
  while (root[i] != i) i = root[i];
  return i;
}

void Union(int i, int j, int *root, int *rank) {
  i = get_root(i, root); j = get_root(j, root);
  if (rank[i] > rank[j]) {
    root[j] = i;
    rank[i] = Max(rank[j] + 1, rank[i]);
  } else {
    root[i] = j;
    rank[j] = Max(rank[i] + 1, rank[j]);
  }
  return;
}

int
main(int argc, char *argv[])
{
  int n, k, l;
  scanf("%d %d %d", &n, &k, &l);
  int root1[200010], root2[200010];
  int rank1[200010] = {}, rank2[200010] = {};
  for (int i = 1; i <= n; i++) root1[i] = root2[i] = i;

  int p, q;
  for (int i = 0; i < k; i++) {
    scanf("%d %d", &p, &q);
    Union(p, q, root1, rank1);
  }
  for (int i = 0; i < l; i++) {
    scanf("%d %d", &p, &q);
    Union(p, q, root2, rank2);
  }

  city a[200010];

  for (int i = 1; i <= n; i++) {
    a[i - 1].number = i;
    a[i - 1].road = get_root(i, root1);
    a[i - 1].railway = get_root(i, root2);
  }

  qsort(a, n, sizeof(city), city_comp);

  int i = 0, ans[200010];
  while (i < n) {
    int j = i + 1;
    while (a[i].road == a[j].road && a[i].railway == a[j].railway) j++;
    for (int k = i; k < j; k++) {
      ans[a[k].number - 1] = j - i;
    }
    i = j;
  }

  for (int i = 0; i < n; i++) printf("%d ", ans[i]); endl;

  return 0;
}
