#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int k = -1;
    for (int i = 2; ; ++i) {
        if (i * (long long)(i - 1) / 2 == n) {
            k = i;
            break;
        }
        else if (i * (long long)(i - 1) / 2 > n) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    cout << k << "\n";
    vector<vector<int>> edges(k, vector<int>(k));
    int c = 0;
    for (int i = 0; i < k; ++i) {
        for (int j = i + 1; j < k; ++j) {
            ++c;
            edges[i][j] = c;
            edges[j][i] = c;
        }
    }
    for (int i = 0; i < k; ++i) {
        cout << k - 1;
        for (int j = 0; j < k; ++j) {
            if (i == j) continue;
            cout << " " << edges[i][j];
        }
        cout << "\n";
    }
    return 0;
}
