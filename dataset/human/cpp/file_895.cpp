#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans;
int main(void){
	int r,g,b,n; cin>>r>>g>>b>>n;
	for(int i=0;i<3005;i++){
		for(int j=0;j<3005;j++){
			int k=n-r*i-g*j;
			if(k>=0&&k%b==0){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	
}
