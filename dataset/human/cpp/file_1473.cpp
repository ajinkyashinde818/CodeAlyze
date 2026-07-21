#include <bits/stdc++.h>
using namespace std;
const int MX = 1e5 + 100;
vector<int> ans[MX];
main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int ss = sqrt(n * 2);
    if(ss * (ss + 1) == n * 2) {
        cout << "Yes\n";
        cout << ss + 1 << endl;
        int ptr = 0;
        vector<int> last;
        for(int i = 1; i <= ss + 1; i ++) {
            for(int j = i; j <= ss; j ++) {
                ans[i].push_back(++ ptr);
            }
        }
        for(int i = 1; i <= ss + 1; i ++) {
            cout << ss << ' ';
            for(int j = 1; j < i; j ++) {
                cout << ans[j][i - j - 1] << ' ';
            }
            for(auto it: ans[i]) cout << it << ' ';
            cout << endl;
        }
    }
    else {
        cout << "No";
    }
}
