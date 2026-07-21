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
   int N, M;
   cin >> N >> M;
   string A[N];
   string B[M];
   for (int i = 0; i < N; i++) cin >> A[i];
   for (int i = 0; i < M; i++) cin >> B[i];

   for (int i = 0; i < N - M + 1; i++) {
      for (int j = 0; j < N - M + 1; j++) {
         bool flg = true;
         for (int k = 0; k < M; k++) {
            string tmp = A[j + k].substr(i, M);
            // cout << k << " " << tmp << endl;
            if (tmp != B[k]) {
               flg = false;
               continue;
            }
         }
         if (flg) {
            cout << "Yes" << endl;
            return 0;
         }
      }
   }
   cout << "No" << endl;
   return 0;
}
