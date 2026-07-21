#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <iomanip>

using namespace std;
// ascending order
#define vsort(v) sort(v.begin(), v.end())
// descending order
#define vsort_r(v) sort(v.begin(), v.end(), greater<int>())
#define vunique(v) unique(v.begin(), v.end())
#define mp make_pair
#define ts(x) to_string(x)
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define repm(i, a, b) for(int i = (int)a; i > (int)b; i--)
#define bit(a) bitset<8>(a)
#define des_priority_queue priority_queue<int, vector<int>, greater<int> >
#define all(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1ll << 60;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    ll a[n];
    rep(i, 0, n) cin >> a[i];
    ll cnt = 0;
    rep(i, 0, n) {
        if(a[i] < 0) {
            cnt++;
            a[i] *= -1;
        }
    }

    sort(a, a + n);
    ll rsl = 0;
    rep(i, 0, n) rsl += a[i];
    if(cnt % 2 == 0) cout << rsl << endl;
    else cout << rsl - 2 * a[0] << endl;
}
