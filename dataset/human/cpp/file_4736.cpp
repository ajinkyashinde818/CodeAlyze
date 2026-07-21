#include <bits/stdc++.h>

using namespace std;

int32_t main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    long long n;

    cin >> n;

    long long r;

    cin >> r;

    if(n<10)

        cout << r + (100*(10-n)) << '\n';

    else

        cout << r << '\n';

    return 0;

}
