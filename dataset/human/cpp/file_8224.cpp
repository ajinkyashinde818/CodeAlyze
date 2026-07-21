#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    long a[200005];
    long long sumleft = 0;
    long long sumright = 0;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> a[i];
        sumright += a[i];
    }
    long long ans = 1e18;
    for(int i=0;i<N-1;i++){
        sumleft += a[i];
        sumright -= a[i];
        ans = min(ans, abs(sumleft - sumright));
    }
    cout << ans << endl;
    return 0;
}
