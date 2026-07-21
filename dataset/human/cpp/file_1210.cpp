#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r,g,b,n;
    cin >> r >> g >> b >> n;

    int cnt=0;
    for(int i = 0; r*i <= n; i++) {
        for(int j = 0; r*i+g*j <=n ; j++) {
            if((n-r*i-g*j)%b==0) cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
