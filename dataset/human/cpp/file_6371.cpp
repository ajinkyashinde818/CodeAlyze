#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    string s; cin >> s;
    int k = 0;
    long long ans = 1;
    const int M = 1000000007;
    for (char c : s) {
        if ((c == 'B') == (k % 2 == 1)) ans = ans * k % M, k--;
        else k++;
    }
    if (k != 0) ans = 0;
    for (int i = 1; i <= n; i++) ans = ans * i % M;
    cout << ans << endl;
}
