#include <bits/stdc++.h>

using namespace std;

int n;

void solve(){
    int i,j;
    string str;
    cin >> n >> j;
    long long ans = 0;
    if(n < 10) ans = j+100*(10-n);
    else ans = j;
    cout << ans << endl;
}

int main(){
    solve();
}
