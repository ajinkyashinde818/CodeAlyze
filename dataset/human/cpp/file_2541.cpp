#include <iostream>
#include<algorithm>
#include<sstream>
#include<stack>
#include<cmath>
#include<vector>
#include<iomanip>
#include<map>
#include<set>
#include<queue>
#include<deque>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < n;i++)
#define ALL(a)  (a).begin(),(a).end()
const int MOD = 998244353;
const ll INF = (1LL << 60);
string s, t, u; ll n, m = 6, k, q = 0, ans, sum =0,b,c = INF; 
int main() {
    cin >> n;
    rep(i, n) {
        cin >> b;
        sum += abs(b);
        if (b < 0)q++;
        c = min(c, abs(b));
    }
    if (q % 2 == 0) cout << sum << endl;
    else cout << sum - 2 * c << endl;
}
