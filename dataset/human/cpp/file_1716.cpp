#include "bits/stdc++.h"
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> ans = {};
    for (int i = 3; i * (i - 1) / 2 <= 100000; i++) {
        ans.push_back(i * (i - 1) / 2);
    }

    bool flag = false;
    int keep = 0;
    for (int i = 0; i < ans.size(); i++) {
        if (N == ans[i]) {
            keep = i;
            flag = true;
        }
    }

    if (N == 1) {
        cout << "Yes" << endl;
        cout << 2 << endl;
        cout << 1 << " " << 1 << endl;
        cout << 1 << " " << 1 << endl;
    }
    else {
        if (flag) {
            int k = keep + 3;
            cout << "Yes" << endl;
            cout << k << endl;

            vector<vector<int>> res(k, vector<int>(0));
            int cnt = 0;
            while (cnt < N * 2) {
                for (int a1 = 0; a1 < k - 1; a1++) {
                    for (int a2 = a1 + 1; a2 < k; a2++) {
                        res[a1].push_back(cnt / 2 + 1);
                        cnt++;
                        res[a2].push_back(cnt / 2 + 1);
                        cnt++;
                    }
                }
            }

            for (int j = 0; j < k; j++) {
                cout << k - 1 << " ";
                for (int l = 0; l < k - 1; l++) {
                    if (l != k - 2) {
                        cout << res[j][l] << " ";
                    }
                    else {
                        cout << res[j][l] << endl;
                    }
                }
            }
        }
        else {
            cout << "No" << endl;
        }
    }
}
