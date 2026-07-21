#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll r,g,b,n;
ll ans=0,tmp=0;

int main(void){
    cin>>r>>g>>b>>n;
    //memset(m,0,sizeof(m));
    for(int i=0;i<=n;i++){
    	for(int j=0;j<=n;j++){
    		/*if(i*r+j*g==n){
    			cout<<i<<j<<endl;
    			ans++;
    		}*/
    		if((n-i*r-j*g)%b==0&&(n-i*r-j*g)>=0){
    		//	cout<<i<<j<<endl;
    			ans++;
    		}
        }
    }

    cout<<ans<<endl;
}
