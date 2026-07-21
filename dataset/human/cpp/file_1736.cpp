#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define all(c) begin(c),end(c)

template<typename T1, typename T2>
inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

//改造
typedef long long int ll;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0 //デバッグする時1にしてね
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//ここから編集する
ll san(ll n) {
    return n * (n - 1) / 2;
}

ll rev(ll n) {
    if (n <= 2) return -1;

    ll lb = 0;
    ll ub = n + 1;
    while (ub - lb > 1) {
        ll mid = (lb + ub) / 2;
        if (san(mid) == n) {
            return mid;
        } else if (san(mid) < n) {
            //midは小さかった...
            lb = mid;
        } else {
            ub = mid;
        }
    }
    return -1;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    if(n == 1){
        cout << "Yes" << endl;
        cout << 2 << endl;
        cout << "1 1" << endl;
        cout << "1 1" << endl;
        return 0;
    }

    int x = (int) rev(n);
    if (x == -1) {
        cout << "No" << endl;
        return 0;
    }

    vector<vector<int> > ans(x);
    int p1 = 0, p2 = 1;
    for (int i = 1; i <= n; ++i) {
        ans[p1].push_back(i);
        ans[p2].push_back(i);
        p2++;
        if (p2 == x) {
            p1++;
            p2 = p1 + 1;
        }
    }

    cout << "Yes" << endl;
    cout << x << endl;
    for (auto vec : ans) {
        cout << vec.size() << " ";
        for (int i = 0; i < vec.size(); ++i) {
            cout << vec[i];
            if (i == vec.size() - 1) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }

    return 0;
}
