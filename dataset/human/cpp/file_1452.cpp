#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <memory>
#include <complex>
#include <numeric>
#include <cstdio>
#include <iomanip>

#define REP(i,m,n) for(int i=int(m);i<int(n);i++)
#define RREP(i,m,n) for(int i=int(n)-1;i>=int(m);--i)
#define EACH(i,c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())

#ifdef LOCAL
#define DEBUG(s) cout << (s) << endl
#define dump(x)  cerr << #x << " = " << (x) << endl
#define BR cout << endl;
#else
#define DEBUG(s) do{}while(0)
#define dump(x) do{}while(0)
#define BR 
#endif
using namespace std;

using UI = unsigned int;
using UL = unsigned long;
using LL = long long int;
using ULL = unsigned long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VS = vector<string>;
using PII = pair<int,int>;
using VP = vector<PII>;

//struct edge {int from, to, cost;};

constexpr double EPS = 1e-10;
//constexpr double PI  = acos(-1.0);
//constexpr int INF = INT_MAX;
constexpr int MOD = 1'000'000'007;

template<class T> inline T sqr(T x) {return x*x;}

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "Yes" << endl;
        cout << "2" << endl;
        cout << "1 1" << endl;
        cout << "1 1" << endl;
    } else if (n == 2) {
        cout << "No" << endl;
    } else {
        for (int i = 1; i * (i - 1) <= 2 * n; ++i) {
            if (i * (i - 1) != 2 * n) continue;
            vector<deque<int>> q(i);
            int index = 0;
            cout << "Yes" << endl;
            cout << i << endl;
            REP(j,0,i) {
                cout << i - 1;
                if (j == 0) {
                    REP(k,0,i-1) {
                        cout << " " << k + 1;
                        q[j].push_back(k);
                        ++index;
                    }
                } else {
                    int cnt = 0;
                    RREP(k,0,j) {
                        if (cnt == i - 1) break;
                        if (!q[k].empty()) {
                            cout << " " << q[k][0] + 1;
                            q[k].pop_front();
                            ++cnt;
                        }
                    }
                    REP(k,cnt,i-1) {
                        cout << " " << index + 1;
                        q[j].push_back(index);
                        ++index;
                    }
                }
                cout << endl;
            }
            return;
        }
        cout << "No" << endl;
    }
}

int main() {
    solve();
    
    return 0;
}
