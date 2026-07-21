#include<stdio.h>
#define NMAX 200000
int UF_find(int, int*);
void UF_union(int, int, int*);
int main(void)
{
  int i, j, n, k, l, rdgrp = 0;
  int droot[NMAX], troot[NMAX], dleaf[NMAX], dnext[NMAX], trgrp[NMAX], trgcnt[NMAX], ans[NMAX] = {0};
  scanf("%d %d %d", &n, &k, &l);
  for (i = 0; i < n; i++) {
    droot[i] = troot[i] = -1;
    dleaf[i] = dnext[i] = -1;
    trgrp[i] = trgcnt[i] = 0;
  }
  for (i = 0; i < k; i++) {
    int p, q, proot, qroot;
    scanf("%d %d", &p, &q);
    UF_union(p - 1, q - 1, droot);
  }
  for (i = 0; i < l; i++) {
    int r, s, rroot, sroot;
    scanf("%d %d", &r, &s);
    UF_union(r - 1, s - 1, troot);
  }
  for (i = 0; i < n; i++) {
    int rd = UF_find(i, droot);
    dnext[i] = dleaf[rd];
    dleaf[rd] = i;
  }
  for (i = 0; i < n; i++) {
    if (dleaf[i] >= 0) {
      rdgrp++;
      for (j = dleaf[i]; j >= 0; j = dnext[j]) {
        int rt = UF_find(j, troot);
        if (trgrp[rt] == rdgrp) trgcnt[rt]++;
        else {
          trgrp[rt] = rdgrp;
          trgcnt[rt] = 1;
        }
      }
      for (j = dleaf[i]; j >= 0; j = dnext[j]) {
        int rt = UF_find(j, troot);
        ans[j] = trgcnt[rt];
      }
    }
  }
  for (i = 0; i < n; i++) printf("%d%c", ans[i], i == n - 1 ? '\n': ' ');
}

int UF_find(int a, int *ufp)
{
  if (ufp[a] < 0) return a;
  else {
    ufp[a] = UF_find(ufp[a], ufp);
    return ufp[a];
  }
}

void UF_union(int a, int b, int *ufp)
{
  a = UF_find(a, ufp);
  b = UF_find(b, ufp);
  if (a == b) return;
  if (ufp[a] < ufp[b]) {
    ufp[a] += ufp[b];
    ufp[b] = a;
  } else {
    ufp[b] += ufp[a];
    ufp[a] = b;
  }
}
