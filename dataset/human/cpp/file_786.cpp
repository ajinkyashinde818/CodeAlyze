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

int main() {
   int R, G, B, N;
   cin >> R >> G >> B >> N;

   int cnt = 0;
   for (int r = 0; r <= N / R; r++) {
      for (int g = 0; g <= N / G; g++) {
         int tmp = r * R + g * G;
         if ((N - tmp) % B == 0 && N - tmp >= 0) {
            cnt++;
         }
      }
   }
   cout << cnt << endl;
   return 0;
}
