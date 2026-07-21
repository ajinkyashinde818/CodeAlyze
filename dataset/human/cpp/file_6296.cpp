#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


bool used[500][500];

signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    cout << fixed << setprecision(20);

    
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll l=0,r=0;
    if(s[0]=='W' || s[2*n-1]=='W'){
        cout<<0<<endl;
        return 0;
    }
    bool left[n*2]={};

    for(ll i=0;i<n*2;i++){
        if(s[i]=='B'){
            if((l-r)%2==0){
                l++;
                left[i]=1;
            }
            else r++;
        }
        else{
            if((l-r)%2==0){
                r++;
            }
            else {
                l++;
                left[i]=1;
            }
        }
    }
    l=0,r=0;
    ll ans = 1;
    ll mod = 1e9+7;
    for(ll i=0;i<2*n;i++){
        //cerr<<left[i]<<" ";
        if(left[i]) l++;
        else{
            ans *= l;
            l--;
            ans %= mod;
        }
        if(l<0){
            cout<<0<<endl;
            return 0;
        }
    }
    if(l){
        cout<<0<<endl;
        return 0;
    }
    //cerr<<endl;
    for(ll i=1;i<=n;i++){
        ans *= i;
        ans %= mod;
    }
    cout<<ans<<endl;
    
}
