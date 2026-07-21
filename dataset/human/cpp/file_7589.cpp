#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using Int = long long;
int main() {
    Int N;
    cin >> N;
    vector<Int> a(N), s(N + 1, 0), ans;
    for (Int i = 0; i < N; i++) {
        cin >> a[i];
        s[i + 1] = s[i] + a[i];
    }
    for (Int i = 0; i < N - 1; i++) {
        Int x = s[i + 1] - s[0];
        Int y = s[N] - s[i + 1];
        ans.push_back(abs(x - y));
    }
    cout << *min_element(ans.begin(), ans.end()) << endl;
}
