#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
template<class T> ostream& operator<<(ostream& os, const vector<T>& vec) { for (auto &vi: vec) os << vi << " "; return os; }

int main() {
    int n; cin >> n;
    long long k = 1;
    while (k * (k + 1) / 2 < n) k++;
    if (k * (k + 1) / 2 != n) return !(cout << "No" << endl);
    cout << "Yes" << endl << k + 1 << endl;
    vector<vector<int>> res(k + 1, vector<int>(k));
    for (int i = 0, cnt = 1; i < k; i++) {
        for (int j = i; j < k; j++) {
            if (j == i) res[k][i] = res[i][i] = cnt++;
            else res[j][i] = res[i][j] = cnt++;
        }
    }
    for (auto &v: res) cout << k << " " << v << endl;
    return 0;
}
