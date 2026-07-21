#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n;
ll a[100005];
ll m=100000000000000000;
ll cnt;
ll sum;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        m=min(m,abs(a[i]));
        sum+=abs(a[i]);
        if(a[i]<0){
            cnt++;
        }
    }
    if(cnt%2==0){
        cout<<sum<<endl;
    }else{
        cout<<sum-m*2<<endl;
    }

}
