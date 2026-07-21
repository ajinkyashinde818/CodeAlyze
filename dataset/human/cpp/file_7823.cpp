#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>

typedef long long ll;
using namespace std;

ll Mod = 1e9 + 7;

int main()
{
    int N;
    ll ans = 3*1e9;
    cin >> N;

    vector <ll> a(N, 0), s(N, 0);

    cin >> a[0];
    s[0] = a[0];
    for (int i = 1; i < N; i++) {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }

    for (int i = 0; i < N-1; i++) {
        ans = min(ans, abs(s[N-1] - 2*s[i]));
    }
    cout << ans << endl;
    return 0;
}
