#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    long long n;
    cin >> n;
    long long ans = 0, arr[n];
    for(long long i = 0; i < n - 1; ++i){
        cin >> arr[i];
        ans += arr[i];
    }
    long long last, rans; cin >> last;
    rans = abs(ans - last);
    for(long long i = n - 2; i > 0; --i){
        rans = min(rans, abs(ans - arr[i] - (last + arr[i])));
        last += arr[i];
        ans -= arr[i];
    }
    cout << rans;
    return 0;
}
