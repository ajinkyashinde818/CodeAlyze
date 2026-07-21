/*  -*- coding: utf-8 -*-
 *
 * a.cc: A - Beginner
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

const int MAX_N = 100;

const int INF = 1 << 30;
const long long LINF = 1LL << 60;

/* typedef */

typedef long long ll;
typedef vector<int> vi;
typedef queue<int> qi;
typedef pair<int,int> pii;

/* global variables */

/* subroutines */

/* main */

int main() {
  int n, r;
  scanf("%d%d", &n, &r);

  printf("%d\n", r + ((n < 10) ? (10 - n) * 100 : 0));
  return 0;
}
