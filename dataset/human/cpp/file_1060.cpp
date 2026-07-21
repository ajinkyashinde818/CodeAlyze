#include<bits/stdc++.h>

using namespace std;
const int N = 1e6+100;
typedef long long ll;
int main(){
	ll R,G,B,n;
	cin>>R>>G>>B>>n;
	ll ans=0;
	for(int i=0;i<=3001;i++){
		for(int j=0;j<=3001;j++){
			if((n-i*R-j*G)>=0&&(n-i*R-j*G)%B==0) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
