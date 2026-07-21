#include <bits/stdc++.h>
using namespace std;
 
ifstream in ("test.in" );
ofstream out("test.out");
 
const int DIM = 2e5 + 5;
 
long long psm[DIM];
 
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
        cin >> psm[i];
        psm[i] += psm[i - 1];
    }
    
    long long ans = numeric_limits<long long> :: max() / 2;
    for (int i = 1; i < n; ++i)
        ans = min(ans, abs(psm[i] - (psm[n] - psm[i])));
    
    cout << ans;
    return 0;
}
