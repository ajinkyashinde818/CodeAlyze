#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cstring>
#include <cmath>
#include <climits>
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <array>
#include <bitset>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define io() ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define fi first
#define se second
#define IN(i,l,r) (l<i&&i<r)
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<=r)
#define v(T) vector<T>
#define p(T, N) pair<T, N>
#define tp(A, B, C) tuple<A, B, C>
#define ii p(int, int)
#define vi v(int)
#define vii v(p(int, int))
#define vvi v(v(int))
#define vl v(long long)
#define vll v(p(long long, long long))
#define si set<int>
#define msi map<string, int>
#define rsz(a) resize(a)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define qsort(a) sort(all(a))
#define qsortd(a) sort(all(a), greater<>())
#define qsortf(a, f) sort(all(a), f)
#define qsortsi(v) sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){return a.se < b.se;})
#define pb(n) push_back(n)
#define eb(n) emplace_back(n)
#define pp(a, b) emplace_back(make_pair(a, b))
#define pt(a, b, c) emplace_back(make_tuple(a, b, c))
#define elif else if
#define fori(i, n) for(ll i = 0; i < n; ++i)
#define foris(i, a, b) for(ll i = a; i < b; ++i)
#define forise(i, a, b) for(ll i = a; i <= b; ++i)
#define ford(i, n) for(ll i = n; i >= 0; --i)
#define fords(i, a, b) for(ll i = a; i >= b; --i)
#define fordse(i, a, b) for(ll i = a; i > b; --i)
#define fora(i, a) for (auto &i: a)
#define rev(a) reverse(a.begin(), a.end())
#define revf(a, b, c) (reverse(a.begin() + b, a.begin() + c))
#define umap unordered_map
#define uset unordered_set
#define pq(T) priority_queue<T>
#define rpq(T) priority_queue<T, vector<T>, greater<T> >
#define nl '\n'
#define fileio(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout)
const int mod = 1000000007;
int digits(int n) {
  n = abs(n);
  if(n < 10) return 1;
  elif(n < 100) return 2;
  elif(n < 1000) return 3;
  elif(n < 10000) return 4;
  elif(n < 100000) return 5;
  elif(n < 1000000) return 6;
  elif(n < 10000000) return 7;
  elif(n < 100000000) return 8;
  elif(n < 1000000000) return 9;
  else return 10;
}


int main() {
  io();
  
  int n, r;
  cin >> n >> r;
  
  if (n >= 10) cout << r;
  else {
    int k = (10 - n) * 100;
    cout << r + k;
  }
  
  return 0;
}
