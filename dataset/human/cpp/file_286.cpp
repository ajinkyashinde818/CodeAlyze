#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF=1e18,MOD=1e9+7;
int main(){
	int r,g,b,n;
	cin>>r>>g>>b>>n;
	int ans=0;
	for(int i=0;i<=3000;i++){
		for(int j=0;j<=3000;j++){
			int ch=r*i+g*j;
			if((n-ch)<0)break;
			if((n-ch)%b==0)ans++;
		}
	}
	cout<<ans<<endl;
}
