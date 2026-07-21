/*  -*- coding: utf-8 -*-
 *
 * c.cc: C - Cell Inversion
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
const int MAX_N2 = MAX_N * 2;
const int MOD = 1000000007;

/* typedef */

typedef long long ll;

/* global variables */

char s[MAX_N2 + 4];
bool ls[MAX_N2];

/* subroutines */

/* main */

int main() {
  int n;
  scanf("%d%s", &n, s);
  int n2 = n * 2;

  int br = 0;
  bool cp = false;
  for (int i = 0; i < n2; i++) {
    bool bk = (s[i] == 'B');
    if (bk != cp) {
      ls[i] = true;
      br++;
    }
    else {
      ls[i] = false;
      br--;
      if (br < 0) {
	puts("0");
	return 0;
      }
    }
    cp ^= true;
  }
  if (br != 0) {
    puts("0");
    return 0;
  }

  int m = 1;
  for (int i = 0, l = 0, r = 0; i < n2; i++) {
    if (ls[i])
      l++;
    else {
      m = (ll)m * (l - r) % MOD;
      r++;
    }
  }

  for (int i = 2; i <= n; i++)
    m = (ll)m * i % MOD;

  printf("%d\n", m);
  return 0;
}
