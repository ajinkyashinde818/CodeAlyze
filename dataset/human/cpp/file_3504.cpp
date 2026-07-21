/*  -*- coding: utf-8 -*-
 *
 * d.cc: D: Flipping Signs
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

const int MAX_N = 100000;
const long long LINF = 1LL << 62;

/* typedef */

typedef long long ll;

/* global variables */

int as[MAX_N];
ll dp[MAX_N + 1][2];

/* subroutines */

inline void setmax(ll &a, ll b) { if (a < b) a = b; }

/* main */

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", as + i);

  for (int i = 0; i < n; i++) dp[i][0] = dp[i][1] = -LINF;
  dp[0][0] = 0;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++)
	setmax(dp[i + 1][k], dp[i][j] + ((j ^ k) ? -as[i] : as[i]));

  printf("%lld\n", dp[n][0]);
  return 0;
}
