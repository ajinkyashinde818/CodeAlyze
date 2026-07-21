#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n, 0), vb(n, 0);
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++) {
        cin >> va[i];
        um[va[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> vb[i];
        um[vb[i]]++;
    }
    for (auto p : um) {
        if (p.second > n) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    deque<pair<int, int>> dq;
    for (int i = 0; i < n; i++) {
        if (va[i] == vb[i]) {
            if (dq.size() > 0 && dq.front().first != va[i]) {
                int index = dq.front().second;
                dq.pop_front();
                swap(vb[i], vb[index]);
            } else {
                dq.push_back(make_pair(va[i], i));
            }
        }
    }
    for (int i = 0; i < n && dq.size() > 0; i++) {
        if (va[i] != dq.front().first && vb[i] != dq.front().first) {
            swap(vb[i], vb[dq.front().second]);
            dq.pop_front();
        }
    }
    for (int i = 0; i < n; i++) {
        cout << vb[i] << " ";
    }
    cout << endl;
}
