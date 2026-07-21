/*  -*- coding: utf-8 -*-
 *
 * f.cc: F - Contrast
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>
 
using namespace std;

/* constant */

const int MAX_N = 200000;

/* typedef */

/* global variables */

int as[MAX_N], bs[MAX_N], ds[MAX_N];
int acs[MAX_N + 1], bcs[MAX_N + 1];

/* subroutines */

void calccs(int n, int vs[], int cs[]) {
  cs[0] = 0;
  for (int v = 1, i = 0; v <= n; v++) {
    while (i < n && vs[i] == v) i++;
    cs[v] = i;
  }
}

/* main */

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", as + i);
  for (int i = 0; i < n; i++) scanf("%d", bs + i);

  calccs(n, as, acs);
  calccs(n, bs, bcs);
  //for (int i = 0; i <= n; i++) printf("%d ", acs[i]); putchar('\n');
  //for (int i = 0; i <= n; i++) printf("%d ", bcs[i]); putchar('\n');

  int maxx = 0;
  for (int i = 1; i <= n; i++) {
    if (acs[i] - acs[i - 1] + bcs[i] - bcs[i - 1] > n) {
      puts("No");
      return 0;
    }

    int x = acs[i] - bcs[i - 1];
    if (maxx < x) maxx = x;
  }
  //printf("maxx=%d\n", maxx);

  for (int i = 0; i < n; i++) ds[(i + maxx) % n] = bs[i];

  puts("Yes");
  for (int i = 0; i < n; i++) {
    printf("%d", ds[i]);
    putchar(i + 1 < n ? ' ' : '\n');
  }
  return 0;
}
