#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = pow(10, 9) + 7;
//const ll MOD = 998244353;
//const ll MOD = ;
ll mod(ll A, ll M) {return (A % M + M) % M;}
const ll INF = 1LL << 60;
template<class T> bool chmin(T& a, T b) {if (a >= b) {a = b; return true;} return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
ll divceil(ll A, ll B) {return (A + (B - 1)) / B;}
ll myctoi(char C) {return C - '0';}
char myitoc(ll N) {return '0' + N;}
#define FINALANS(A) {cout << (A) << endl; exit(0);}

int main()
{
  ll N;
  cin >> N;
  string S;
  cin >> S;

  ll ans = 1;
  ll T = 0, t = 0;
  for (ll i = 0; i < 2 * N; i++)
  {
    bool b = (S.at(i) == 'B');
    //cerr << t << " " << b << endl;
    if ((t % 2) ^ b)
    {
      ans *= N - T;
      ans %= MOD;
      t++, T++;
    }
    else
    {
      ans *= t;
      ans %= MOD;
      t--;
    }

    //cerr << ans << endl;

    if (t < 0 || t > N)
      FINALANS(0);
  }

  cout << ans << endl;
}
