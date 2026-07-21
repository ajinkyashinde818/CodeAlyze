#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define REP(i,n) for (int i = 0; i < n; i++)
typedef long long ll;

int main ()
{

    int n; cin >> n;

    if (n == 1) {
        cout << "Yes" << endl;
        cout << 2 << endl;
        cout << 1 << " " << 1 << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }

    if (n == 2) {
        cout << "No" << endl;
        return 0;
    }

    int v = -1;
    for (int i = 3; i <= 1000; i++) {
        if (i * (i - 1) / 2 == n) {
            v = i;
            goto nxt;
        }
    }

    cout << "No" << endl;
    return 0;

    nxt:;

    vector < vector < int > > ans;
    ans.push_back({1, 2});
    ans.push_back({1, 3});
    ans.push_back({2, 3});

    int cnt = 4;
    for (int i = 0; i < v - 3; i++) {
        vector < int > add;
        REP(j,ans.size()) {
            ans[j].push_back(cnt);
            add.push_back(cnt);
            cnt++;
        }
        ans.push_back(add);
    }

    cout << "Yes" << endl;
    cout << ans.size() << endl;
    REP(i,ans.size()) {
        cout << ans[i].size();
        REP(j,ans[i].size()) {
            cout << " " << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}
