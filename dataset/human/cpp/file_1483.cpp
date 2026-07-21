// 基本テンプレート
 
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
using namespace std;
 
#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(int (i)=(a); (i)<=(n); (i)++)
#define repr(i,a,n) for(int (i)=(a); (i)>=(n); (i)--)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define int long long int
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
typedef pair<int, int> pii;
typedef long long ll;
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const ll INF = 1001001001001001LL;
const ll MOD = 1000000007LL;
 
signed main() {
    int N; cin >> N;
    int M = N, cnt = 1;
    for(cnt=1; M>0; cnt++) M -= cnt;
    if(M < 0) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        vector< vector<int> > sets(cnt);

        int id = 1;
        for(int i=0; i<cnt; i++) {
            for(int j=i+1; j<cnt; j++) {
                sets[i].push_back(id  );
                sets[j].push_back(id++);
            }
        }

        cout << cnt << endl;
        for(int i=0; i<cnt; i++) {
            cout << sets[i].size() << " ";
            for(int j=0; j<sets[i].size(); j++) {
                cout << sets[i][j] << " \n"[j + 1 == sets[i].size()];
            }
        }
    }
    return 0;
}
