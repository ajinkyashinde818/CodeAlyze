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
  vector<int> a(N);
  long long sum = 0;
  for (int i = 0; i < N; i++) 
  {
    long long A;
    cin >> A;
    sum += A;
    a.at(i) = A;
  }
  
  long long sum0 = 0;
  long long ans = INF;
  for (int i = 0; i < N - 1; i++)
  {
    sum0 += a.at(i);
    chmin(ans, abs(sum0 - (sum - sum0)));
  }
  
  cout << ans << endl;
}
