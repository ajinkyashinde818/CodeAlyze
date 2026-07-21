#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(12);

    int n;
    int m;
    cin >> n >> m;

    vector<string> A(n);
    vector<string> B(m);

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> B[i];
    }

    if (n < m) {
        cout << "No\n";
        return 0;
    }

    vector<vector<int>> cnts(n + n + 1, vector<int>(n + n + 1, 0));

    vector<vector<pair<int,int>>> pos(2);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            int idx = B[i][j] == '.' ? 0 : 1;
            pos[idx].emplace_back(i, j);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int idx = A[i][j] == '.' ? 0 : 1;
            for (auto& p : pos[idx]) {
                int x = p.first, y = p.second;
                if (-x + i >= 0 && -y + j >= 0) {
                    cnts[-x + i][-y + j] += 1;
                }
            }
        }
    }

    bool res = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (cnts[i][j] == m * m) {
                res = true;
            }
        }
    }

    if (res) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }


    return 0;
}
