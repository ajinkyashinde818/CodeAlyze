#include<iostream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>

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
void add(long long &a, long long b) { a += b; if (a >= MOD) a -= MOD; }

ll absll(ll a) {
   if (a < 0) return -a;
   else return a;
}

int main() {
   int N;
   cin >> N;
   ll A[N];
   int minus = 0;
   for (int i = 0; i < N; i++) {
      cin >> A[i];
      if (A[i] < 0) minus++;
   }
   sort(A, A + N);
   ll ans = 0;
   if (minus % 2 == 0) {      
      for (int i = 0; i < N; i++) {
         ans += absll(A[i]);
      }
   } else {
      for (int i = 0; i < N; i++) {
         if (i != minus && i != minus - 1) {
            ans += absll(A[i]);
         }
      }
      if (minus != N) ans += absll(A[minus] + A[minus - 1]);
      else ans += A[minus - 1];
   }
   cout << ans << endl;
   return 0;
}
