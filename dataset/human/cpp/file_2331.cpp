#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int counter = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] < 0) {
            counter++;
        }
    }
    for(int i = 0; i < n; i++) {
        a[i] = abs(a[i]);
    }
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        ans += a[i];
    }
    if(counter % 2 != 0) {
        ans -= 2 * *min_element(a.begin(), a.end());
    }
    cout << ans << "\n";
    return 0;
}
