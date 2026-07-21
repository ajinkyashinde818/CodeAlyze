#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n;
long long a[200005];
long long s[200005];
long long ans=1e18;
int main(){
	cin>>n;
//	cout<<n<<endl;
	for (int i=1;i<=n;i++){
		cin>>a[i];
//		cout<<i<<endl;
		//s[i]=s[i-1]+a[i];
	}
//	return 0;
	for (int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		//cout<<s[i]<<" ";
	}
	
	for (int i=1;i<=n-1;i++){
		ans=min(ans,abs(s[i]-s[n]+s[i]));
	}
	cout<<ans;
	return 0;
}
