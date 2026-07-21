/*  -*- coding: utf-8 -*-
 *
 * b.cc: B: Template Matching
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

const int MAX_N = 50;
const int MAX_M = 50;

/* typedef */

/* global variables */

string as[MAX_N], bs[MAX_M];

/* subroutines */

/* main */

int main() {
  int n, m;
  cin >> n >> m;
  for (int y = 0; y < n; y++) cin >> as[y];
  for (int y = 0; y < m; y++) cin >> bs[y];

  bool ng = true;
  for (int dy = 0; ng && dy + m <= n; dy++)
    for (int dx = 0; ng && dx + m <= n; dx++) {
      bool ok = true;
      for (int y = 0; ok && y < m; y++)
	for (int x = 0; ok && x < m; x++)
	  ok = (bs[y][x] == as[y + dy][x + dx]);
      ng = (! ok);
    }

  if (ng) puts("No");
  else puts("Yes");
  return 0;
}
