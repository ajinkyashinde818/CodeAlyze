#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <tuple>
#include <cmath>
using namespace std;
using Int = long long;
int main()
{
    int N; cin >> N;
    int k;
    for (k = 2; k <= 447; k++) {
        int M = k * (k - 1) / 2;
        if (N == M) {
            goto YES;
        }
    }
    cout << "No" << endl;
    return 0;
YES:
    vector<vector<int>> T(k);
    int n = 1;
    for (int a = 0; a < k; a++) {
        for (int b = a + 1; b < k; b++) {
            T[a].push_back(n);
            T[b].push_back(n);
            n++;
        }
    }
    cout << "Yes" << endl;
    cout << k << endl;
    for (int i = 0; i < k; i++) {
        cout << T[i].size() << ' ';
        for (int j = 0; j < T[i].size(); j++) {
            cout << T[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
