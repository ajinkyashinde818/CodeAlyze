#include <algorithm>
#include <bits/stdc++.h>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <map>
#include <math.h>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

#define REP(i, n) for(int i = 0; i != n; ++i)
#define REPR(i, n) for(int i = n - 1; i != -1; --i)
#define FOR(i, a, b) for(int i = a; i != b; ++i)
#define RBF(i, n) for(auto &i : n)
#define ABS(n) (n < 0 ? -n : n)
#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)
#define IN(n) (cin >> n)
#define OUT(n) (cout << n << "\n")
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()

using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false); //cinの高速化
  
  int N;
  IN(N);
  vector<ll> X(N);
  int minus=0;
  ll sum=0;
  ll min;
  REP(i,N){
    IN(X[i]);
    if(X[i]<0){
      ++minus;
      X[i] *=-1; 
    }
    sum += X[i];
    if(i==0) min = X[i];
    if(X[i]< min) min = X[i];    
  }
  if(minus%2 ==1){
    sum -= min *2;
  }
  OUT(sum);
  return 0;
}
