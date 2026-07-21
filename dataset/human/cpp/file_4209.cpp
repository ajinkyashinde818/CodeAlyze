#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 7;

int main() {
    long long n, ans = 2;
    cin >> n;
    if(n <= 3) {
        cout << n << endl;
        return 0;
    }
    n--;
    long long tmp = 3, mx = 3, now;
    while(1) {
        now = tmp + mx*4;
        if(now <= n) {tmp = now, mx *= 3, ans += 2;}
        else break;
    }
    n -= tmp;
    now = mx;
    while(n > 0 && now >= 1) {
        ans += (n/now);
        n %= now;
        now /= 3;
    }
    ans += (n/mx);
    cout << ans << endl;
    return 0;
}
