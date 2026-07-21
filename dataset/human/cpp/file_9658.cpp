#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set> 
#include <map>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <cctype>
#define REP(i,n) for(int i=0; i<(n); ++i)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const ll INFLL = 1001001001001001001;  // > 10^18
const int MOD = (int)1e9 + 7;
const ll MODLL = (ll)1e9 + 7;
const double EPS = 1e-9;



int main () {

    int n,m; cin >>n>>m;
    vector<vector<char> > a(n, vector<char>(n)); REP(i,n) REP(j,n) cin >> a[i][j];
    vector<vector<char> > b(m, vector<char>(m)); REP(i,m) REP(j,m) cin >> b[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool flag = true;
            for (int k = 0; k < m; k++) {
                for (int l = 0; l < m; l++) {
                    if (i+k >= n || j+l >= n || b[k][l] != a[i+k][j+l]) {
                        flag = false;
                    } 
                }
            }
            if (flag) {
                cout << "Yes" << endl;
                return 0;
            } 
        }
    }

    cout << "No" << endl;
    return 0;
}
