#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long sum[n] = {};
    for(int i=0; i<n; i++){
        long long t;
        cin >> t;
        if(i==0){
            sum[i] = t;
        }else{
            sum[i] = sum[i-1] + t;
        }
    }
    long long ans = 1e12;
    for(int i=0; i<n-1; i++){
        ans = min(ans, abs(sum[n-1] - sum[i]*2));
    }
    cout << ans << endl;
    return 0;
}
