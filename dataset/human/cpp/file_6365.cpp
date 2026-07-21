#include<iostream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>

using namespace std;

typedef long long ll;

typedef std::pair<int, int> ipair;
bool lessPair(const ipair& l, const ipair& r){return l.second < r.second;}
bool morePair(const ipair& l, const ipair& r){return l.second > r.second;}

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const ll MOD = 1e9 + 7;
// const long long INF = 1LL<<60;
void add(long long &a, long long b) { a += b; if (a >= MOD) a -= MOD; }
void sub(long long &a, long long b) { a -= b; if (a < 0) a += MOD; }
void mul(long long &a, long long b) { a *= b; a %= MOD; }
ll llmin(ll a, ll b) { if (a < b) return a; else return b; }
ll llmax(ll a, ll b) { if (a < b) return b; else return a; }
ll llabs(ll a) { if (a >= 0) return a; else return - a; }
ll llmodpow(ll a, ll n) {
   if (n == 0) return 1;
   ll tmp = llmodpow(a, n / 2);
   mul(tmp, tmp);
   if (n & 1) mul(tmp, a);
   return tmp;
}

int main() {
   int N;
   string S;
   cin >> N >> S;

   if (S[0] == 'W' || S[2 * N - 1] == 'W') {
      cout << 0 << endl;
      return 0;
   }
   string S2 = "L";
   int cntL[2 * N];
   int cntR[2 * N];
   cntR[0] = 0;
   cntL[0] = 1;
   for (int i = 1; i < 2 * N - 1; i++) {
      if (S[i] == 'W') {
         if ((cntL[i - 1] - cntR[i - 1]) % 2 == 1) {
            S2 += "L";
            cntL[i] = cntL[i - 1] + 1;
            cntR[i] = cntR[i - 1];
         } else {
            S2 += "R";
            cntR[i] = cntR[i - 1] + 1;
            cntL[i] = cntL[i - 1];
         }
         if (cntL[i] < cntR[i]) {
            cout << 0 << endl;
            return 0;
         }
      } else {
         if ((cntL[i - 1] - cntR[i - 1]) % 2 == 0) {
            S2 += "L";
            cntL[i] = cntL[i - 1] + 1;
            cntR[i] = cntR[i - 1];
         } else {
            S2 += "R";
            cntR[i] = cntR[i - 1] + 1;
            cntL[i] = cntL[i - 1];
         }
         if (cntL[i] < cntR[i]) {
            cout << 0 << endl;
            return 0;
         }
      }
   }
   S2 += "R";
   cntL[2 * N - 1] = cntL[2 * N - 2];
   cntR[2 * N - 1] = cntR[2 * N - 2] + 1;
   if (cntL[2 * N - 1] != cntR[2 * N - 1]) {
      cout << 0 << endl;
      return 0;
   }
   // cout << S2 << endl;
   /*   
   for (int i = 0; i < 2 * N; i++) {
      cout << i << " " << cntL[i] << " " << cntR[i] << endl;
   }
   */
   ll ans = 1;
   for (int i = 1; i < 2 * N; i++) {
      if (S2[i] == 'L') continue;
      ans *= cntL[i - 1] - cntR[i - 1];
      // cout << i << " " << cntL[i - 1] - cntR[i - 1] << endl;
      ans %= MOD;
   }
   // cout << ans << endl;
   for (int i = 1; i <= N; i++) {
      ans *= i;
      ans %= MOD;
   }
   cout << ans << endl;
   return 0;
}
