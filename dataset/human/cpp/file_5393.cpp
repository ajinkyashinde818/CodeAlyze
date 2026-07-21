#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N,R; cin >> N >> R;

    if(N < 10) cout << R+100*(10-N) << endl;
    else cout << R << endl;

    return 0;

}
