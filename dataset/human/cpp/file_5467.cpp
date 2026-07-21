#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
const ll mod = 1e9+7;

//* Author :- Amey :P *//
void swap(ll &a , ll &b){
    ll t = a;
    a = b;
    b = t;
}

ll min(ll a, ll b){
    if(a<b)return a;
    return b;
}

ll max(ll a, ll b){
    if(a>b)return a;
    return b;
}
 ll pow(ll a, ll b) {
    a %= mod;
    ll ans = 1;
    while (b > 0) {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return ans;
}






int main(){

//   #ifndef ONLINE_JUDGE
//      freopen("input.txt", "r", stdin);
//   #endif
   ll n;
   cin>>n;
   ll r;
   cin>>r;

   if(n >= 10){
    cout<<r<<endl;
   }else{
    cout<<r+(100*(10-n))<<endl;
   }

}
