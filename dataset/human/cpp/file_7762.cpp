#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long n,a[200005],s[200005];
long long sum(0),ans=2e14;
int main(){
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i];
		if(!i) s[i]=a[i];
		else s[i]=s[i-1]+a[i];
		sum+=a[i];
	}
	for(int i=0;i<n-1;++i){
		ans=min(abs(s[i]-(sum-s[i])),(long long)ans);
	}
	cout<<ans<<endl;
	return 0;
}
