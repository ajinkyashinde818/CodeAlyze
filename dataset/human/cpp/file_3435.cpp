#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a.at(i);
    }
    
    sort(a.begin(), a.end());
    long long ans = 0; 
    for(int i = 0; i < n; i += 2)
    {
        if (n % 2 == 1) {
            if (i + 1 == n) {
                ans += a.at(i);
                break;
            }
        }
        if (a.at(i) < 0 && a.at(i + 1) < 0) ans += -1 * a.at(i) + -1 * a.at(i + 1);
        else if (a.at(i) < 0) ans += max((a.at(i) + a.at(i + 1)), (-1 * a.at(i) + -1 * a.at(i + 1)));
        else ans += max(a.at(i) + a.at(i + 1), -1 * a.at(i) + -1 * a.at(i + 1));
    }
    cout << ans << endl;
}
