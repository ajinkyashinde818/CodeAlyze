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
  int N, M;
  cin >> N >> M;
  vector<string> A(N), B(M);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  for (int i = 0; i < M; i++) cin >> B.at(i);
  
  string ans = "No";
  for (int i = 0; i < N - M + 1; i++)
  {
    for (int j = 0; j < N - M + 1; j++)
    {
      bool flg = true;
      for (int k = 0; k < M; k++)
      {
        string S = (A.at(j + k).substr(i, M));
        if (S != B.at(k)) {flg = false; break;}
      }
      if (flg) {ans = "Yes"; break;}
    }
  }
  
  cout << ans << endl;
}
