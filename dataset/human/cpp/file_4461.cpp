/*
 * b.cc: 
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

/* typedef */

/* global variables */

/* subroutines */

/* main */

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    if (i) putchar(' ');
    printf("%d", (i < n / 2 + 1) ? 0 : m);
  }
  putchar('\n');
  return 0;
}
