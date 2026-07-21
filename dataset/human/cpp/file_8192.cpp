#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<deque>
#include<math.h>
using namespace std;
#define ll long long
int main(){
    ll N;
    cin >> N;
    ll i;
    ll A[N];
    ll sum[N+1];
    sum[0]=0;
    for(i=0;i<N;i++){
        cin >> A[i];
        sum[i+1]=sum[i]+A[i];
    }
    ll ans=100000000000;
    for(i=1;i<N;i++){
        ans=min(ans,abs(sum[N]-2*sum[i]));
    }
    cout << ans;
    return 0;
}
