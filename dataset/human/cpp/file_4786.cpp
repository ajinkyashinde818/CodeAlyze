#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int INF = 1<<30;
const long long LINF = 1LL<<60;

int main(){
    int n, r, ans = 0;
    cin >> n >> r;
    ans = r + max(0, 100 * (10 - n));
    cout << ans << endl;
    return 0;
}
