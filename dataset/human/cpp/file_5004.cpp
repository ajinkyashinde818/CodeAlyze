#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<iomanip>
#include<map>
#include<utility>
#include<string>
#include<unordered_map>
#include<queue>

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;

#define min_3(a, b, c) min(a, min(b, c))
#define max_3(a, b, c) max(a, max(b, c))
typedef long long ll;
typedef pair<int, int> P;
const ll INF = ll(1e18)+1;

int main(){
   int n, r;
   cin >> n >> r;
   if(n >= 10) cout << r << endl;
   else cout << r+100*(10-n) << endl;
   return 0;
}
