#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& e : a) cin >> e;

    int64_t ans = 0;
    for (auto& e : a) ans += abs(e);
    int nc = 0;
    for (auto& e : a) if (e < 0) nc++;
    if(nc%2 != 0 && find(a.begin(), a.end(), 0) == a.end()) {
        vector<int> absn;
        for (auto& e : a) absn.push_back(abs(e));
        ans -= (*min_element(absn.begin(), absn.end())*2);
    } 
    cout << ans << endl;
    return 0;
}
