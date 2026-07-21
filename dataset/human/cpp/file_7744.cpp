#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    long long int a[200000];
    long long int ans = 0;
    long long int l=0, r=0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        r += a[i];
    }
    l = a[0];
    r -= a[0];
    ans = abs(l-r);
    for(int i = 1; i < n-1; i++){
        l += a[i];
        r -= a[i];
        if(ans > abs(l-r))  ans = abs(l-r);
    }
    cout << ans << '\n';
    return 0;
}
