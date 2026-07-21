#include<bits/stdc++.h>

using namespace std;
long long a[100005];
int main(){
	long long n;
	cin>>n;
	long long mn=1e9;
	long long ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]<=0)ans++;
		mn=min(mn,abs(a[i]));
	}
	long long ans2=0;
	for(int i=0;i<n;i++)ans2+=abs(a[i]);
	if(ans%2!=0){
		ans2-=2*(mn);
	}
	cout<<ans2<<endl;
	return 0;
}
