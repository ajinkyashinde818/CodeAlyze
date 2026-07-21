#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <numeric>
#include <utility>
#include <iomanip>

using namespace std;
using int64 = long long;

struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<m; i++) cin >> b[i];
    
    bool ans = false;
    for (int y=0; y<=n-m; y++) {
        for (int x=0; x<=n-m; x++) {
            bool f = true;
            for (int i=0; i<m; i++) {
                if (a[y+i].substr(x, m) != b[i])
                    f = false;
            }
            if (f) ans = true;
        }
    }
    
    cout << (ans?"Yes":"No") << endl;
}
