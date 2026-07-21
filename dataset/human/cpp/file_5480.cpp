#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main()
{
    int n, r;
    cin >> n >> r;
    int ans = r;
    if (n < 10) {
        ans += 100 * (10 - n);
    }
    cout << ans << endl;
    return 0;
}
