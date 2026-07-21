#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, r;
    cin >> n >> r;
    int i;
    if (n >= 10) i = r;
    else i = r + 100 * (10 - n);
    cout << i << "\n";    
    return 0;
}
