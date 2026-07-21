#include <bits/stdc++.h>
using namespace std;
const long long mod = pow(10, 9) + 7;
const long long MOD = 998244353;
const long long INF = 1LL << 60;
const int inf = pow(10, 9) + 7;
template <class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template <class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
int divCeil(int A, int B) {return (A + (B - 1)) / B;}
long long divCeil(long long A, int B) {return (A + (B - 1)) / B;}
long long divCeil(int A, long long B) {return (A + (B - 1)) / B;}
long long divCeil(long long A, long long B) {return (A + (B - 1)) / B;}

int main()
{
  int N;
  cin >> N;
  vector<long long> A(N);
  
  long long sum = 0;
  long long minus = 0;
  long long min = INF;
  for (int i = 0; i < N; i++) 
  {
    long long a;
    cin >> a;
    A.at(i) = a;
    sum += abs(a);
    if (a < 0) minus++;
    chmin(min, abs(a));
  }
  
  long long ans;
  if (minus % 2 == 0) ans = sum;
  else ans = sum - min * 2;
  
  cout << ans << endl;
}
