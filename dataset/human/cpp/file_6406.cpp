#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> mp;
ll inf =  1e9;
ll mod = 1e9 + 7;

int main(){
    ll n;
    string s;
    cin>>n>>s;
    vector<int> a(2*n);
    for(int i=0;i<2*n;i++){
	if(s[i] == 'W'){
	    a[i] = 0;
	}else{
	    a[i] = 1;
	}
    }
    int cnt = 0;
    vector<int> used(2*n);
    for(int i=0;i<2*n;i++){
	if(cnt < 0){
	    cout<<0<<endl;
	    return 0;
	}
	if((i+1)%2 == a[i]){
	    used[i] = 1;
	    cnt++;
	}else{
	    used[i] = -1;
	    cnt--;
	}
    }
   if(cnt!=0){
	//cout<<cnt<<endl;
	cout<<0<<endl;
	return 0;
    }
   // for(int i=0;i<2*n;i++)cout<<used[i]<<endl;
    ll res = 1;
    cnt = 0;
    for(int i=0;i<2*n;i++){
	if(used[i]==1){
	    cnt++;
	}else{
	    res *= cnt;
	    res %= mod;
	    cnt--;
	}
    }
    for(ll i=1;i<=n;i++){
	res *= i;
	res %= mod;
    }
	//    cout<<"OK"<<endl;
    cout<<res<<endl;

    return 0;
}
