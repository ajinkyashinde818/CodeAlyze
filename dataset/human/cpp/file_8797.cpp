#include <iostream>
#include <utility>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <array>
#include <math.h>
#include <numeric>
#include <sstream>
typedef long long ll;
using namespace std;

int n, m;
vector<string> a;
vector<string> b;

bool judge(int y, int x) {
    bool f = true;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (b[i][j] != a[i+y][j+x]) f = false;
        }
    }
    return f;
}

int main(int argc, char const *argv[]) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string t;
        cin >> t;
        a.push_back(t);
    }
    for (int i = 0; i < m; ++i) {
        string t;
        cin >> t;
        b.push_back(t);
    }
    for (int i = 0; i < n-m+1; ++i) {
        for (int j = 0; j < n-m+1; ++j) {
            bool f = judge(i, j);
            if (f) {
                cout << "Yes" << std::endl;
                return 0;
            }
        }
    }
    cout << "No" << std::endl;
    return 0;
}
