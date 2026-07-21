#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    int k;
    for (k = 2;; k++) {
        int t = k * (k - 1) / 2;
        if (t >= n) {
            if (t == n) {
                cout << "Yes" << endl;
                cout << k << endl;
                vector<vector<int>> a(k, vector<int>());
                int x = 0;
                for (int i = 0; i < k; i++) {
                    for (int j = 0; j < i; j++) {
                        x++;
                        a[i].push_back(x);
                        a[j].push_back(x);
                    }
                }
                for (int i = 0; i < k; i++) {
                    cout << a[i].size();
                    for (int j = 0; j < a[i].size(); j++) {
                        cout << ' ' << a[i][j];
                    }
                    cout << endl;
                }
            } else {
                cout << "No" << endl;
            }
            break;
        }
    }

    return 0;
}
