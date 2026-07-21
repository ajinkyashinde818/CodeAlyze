#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200];
int main(void){
	int n; cin>>n;
	ll ans=1;
    string s; cin>>s;
    for(int i=0;i<n;i++){
		int k=s[i];
		//cout<<k<<endl;
		a[k]++;
	}
	for(int i=97;i<=123;i++){
		if(a[i]>0){
			ans=ans*(1+a[i])%1000000007;
		}
	}
    cout<<ans-1<<endl;
    
}
