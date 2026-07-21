#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,r;
    cin >> n >> r;
    int ans;
    if(n>=10) ans = r;
    else ans = r+100*(10-n);
    cout << ans << endl;
    return 0;
}
