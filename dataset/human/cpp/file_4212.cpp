#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#ifndef LOCAL
#define debug(x) ;
#else
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << '{';
  for (const T &item : v) out << item << ", ";
  out << "\b\b}";
  return out;
}
#endif

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 200010


int main(){
  ll N;
  int ans = 0, counter[50] = {};

  cin >> N;

  for (int i=0; N; i++) {
    counter[i] += N % 3;
    N /= 3;
  }

  for (int i=0; i<50; i++) {
    bool first = true;
    for (int j=48; j>=0; j--) {
      if(((!(first || j == 0) && counter[j] <= 1) ||
         ((first || j == 0) && counter[j] == 0)) && counter[j+1]) {
        counter[j+1]--;
        counter[j] += 3;
      }
      first &= counter[j] == 0;
    }
  }

  for (int i=0; i<50; i++) {
    debug(counter[i]);
    ans += counter[i];
  }

  cout << ans << endl;

  return 0;
}
