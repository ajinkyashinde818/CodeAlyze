#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int minus = 0;
    ll a[100007];
    ll least = 1000000007;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ans += abs(a[i]);
        least = min(least, abs(a[i]));
        if(a[i] < 0){
            minus++;
        }
    }
    if(minus % 2 == 0){
        cout << ans << endl;
    }
    else{
        cout << ans - least * 2 << endl;
    }
}
