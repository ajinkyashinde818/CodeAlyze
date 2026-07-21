#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,i,a[200005],memo,plus=1;
    long long ans=1,mod=1e9+7;
    char s[200005];
    cin >> n >> s;
    n=2*n;
    for(i=0;i<n;i++){
    	if(s[i]=='B') a[i+1]=1;
    	else a[i+1]=0;
    }
    if(a[1]==0||a[n]==0){
    	cout << "0" << endl;
    	return 0;
    }
    n=n/2;
    for(i=1;i<=n;i++) ans=ans*i%mod;
    if(a[2]==1){
    	memo=0;
    	plus=-1;
    } else {
    	memo=2;
    	plus=1;
    }
    for(i=3;i<=2*n;i++){
    	if(memo>(2*n-i+1)){
    		cout << "0" << endl;
    		return 0;
    	}
    	if(a[i-1]==a[i]&&plus==1){
    		ans=ans*memo%mod;
    		memo--;
    		plus=-1;
    	} else if(a[i-1]==a[i]&&plus==-1){
    		memo++;
    		plus=1;
    	} else if(a[i-1]!=a[i]&&plus==1){
    		memo++;
    		plus=1;
    	} else if(a[i-1]!=a[i]&&plus==-1){
    		ans=ans*memo%mod;
    		memo--;
    		plus=-1;
    	}
    }
    cout << ans << endl;
    return 0;
}
