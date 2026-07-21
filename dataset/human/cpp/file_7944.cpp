#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <numeric>
#include <functional>
#include <cmath>
#include <cassert>
#include <string>
#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
const ll MOD = 1000000007;
const int mod = 1000000007;
ll INF = 1LL << 60;

template <typename T>
istream &operator>>(istream &is, vector<T> &vec)
{
   for (auto &v : vec)
      is >> v;
   return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
   os << "[";
   for (auto v : vec)
      os << v << ",";
   os << "]";
   return os;
}
template <typename T>
ostream &operator<<(ostream &os, const deque<T> &vec)
{
   os << "deq[";
   for (auto v : vec)
      os << v << ",";
   os << "]";
   return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &vec)
{
   os << "{";
   for (auto v : vec)
      os << v << ",";
   os << "}";
   return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &vec)
{
   os << "{";
   for (auto v : vec)
      os << v << ",";
   os << "}";
   return os;
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &vec)
{
   os << "{";
   for (auto v : vec)
      os << v << ",";
   os << "}";
   return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_multiset<T> &vec)
{
   os << "{";
   for (auto v : vec)
      os << v << ",";
   os << "}";
   return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &pa)
{
   os << "(" << pa.first << "," << pa.second << ")";
   return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const map<TK, TV> &mp)
{
   os << "{";
   for (auto v : mp)
      os << v.first << "=>" << v.second << ",";
   os << "}";
   return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp)
{
   os << "{";
   for (auto v : mp)
      os << v.first << "=>" << v.second << ",";
   os << "}";
   return os;
};
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val)
{
   fill((T *)array, (T *)(array + N), val);
}


ll a[202020];
int solve()
{
   ll n;
   cin >> n;
   //ll y = 0;
   for(int i=0; i < n; i++){
      cin >> a[i];
     // y += a[i];
   }
   ll y = accumulate(a, a + n, 0LL);
   ll ans = (1LL << 61) , x = 0;
   for(int i=0; i < n-1; i++){
      y -= a[i];
      x += a[i];
      ans = min(ans, abs(x - y));
   }
   cout << ans << endl;
   return 0;
}

int main()
{
   //cout.precision(10)
   ios::sync_with_stdio(false);
   cin.tie(0);

   solve();
}
