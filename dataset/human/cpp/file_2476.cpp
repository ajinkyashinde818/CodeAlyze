#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a;
    long long ans=0;
    bool flag=false;

    cin >> n;

    for (int i = 0 ; i < n ; ++i) {
        cin >> a;
        
        if (a < 0) {
            a *= -1;
            flag = !flag;
        }

        if (i == 0 || a < m) m = a;
        ans += a;
    }


    if (flag) ans -= m*2;

    cout << ans;

    return 0;
}
