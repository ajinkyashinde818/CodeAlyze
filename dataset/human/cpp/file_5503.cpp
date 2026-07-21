#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, r;
    cin >> n >> r;

    int ans = 0;
    if(n >= 10){
        ans = r;
    }else{
        ans = r + 100 * (10 - n);
    }

    cout << ans << endl;

    return 0;
}
