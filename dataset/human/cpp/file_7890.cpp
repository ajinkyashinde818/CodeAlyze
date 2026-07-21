#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    ll sufix[n+1];
    sufix[n] = 0;
    for(int i=n-1;i>=0;i--){
        sufix[i] = sufix[i+1] + a[i];
    }
    ll dif = 1e17, sum = 0;
    for(int i=0;i<n-1;i++){
        sum += a[i];
        dif = min(dif,abs(sum-sufix[i+1]));
    }
    cout<<dif<<"\n";
    return 0;
}
