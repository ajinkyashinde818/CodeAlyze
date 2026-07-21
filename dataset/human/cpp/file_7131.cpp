#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;  cin >> n;   long long int ans = 10000000000000000, sum = 0;
    vector<long long int> vec(n);
    for(int i = 0;n > i;i++){
        cin >> vec[i];  sum += vec[i];
    }
    for(int i = 0;n-1>i;i++){
        sum -= 2*vec[i];  ans = min(ans, abs(sum));
        // cout << i << " " << sum << " " << ans << "\n";
    }
    // ans = min(ans, abs(sum));
    cout << ans;
    
}
