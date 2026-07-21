/*  -*- coding: utf-8 -*-
 *
 * 1367.cc: Rearranging a Sequence
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
const int MAX_M = 100000;

/* typedef */

/* global variables */

int es[MAX_M];
bool used[MAX_N + 1];

/* subroutines */

/* main */

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  for (int i = 0; i < m; i++) scanf("%d", es + i);

  for (int i = m - 1; i >= 0; i--)
    if (! used[es[i]]) printf("%d\n", es[i]), used[es[i]] = true;
  for (int i = 1; i <= n; i++)
    if (! used[i]) printf("%d\n", i);
  return 0;
}
