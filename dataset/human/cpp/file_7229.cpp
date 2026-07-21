#include<bits/stdc++.h>
using namespace std;
const long long int inf=9999999999999999;
int main(){
	int n;cin>>n;
	vector<long long int>a(n);
	vector<long long int>b(n);
	for(int i=0;i<n;++i){
		cin>>a[i];
		b[0]=a[0];
		if(i!=0)b[i]=b[i-1]+a[i];
	}
	long long int ans=inf;
	for(int i=0;i<n-1;i++){
		long long int s_ans=abs(b[i]-(b[n-1]-b[i]));
		ans=min(ans,s_ans);
	}
	cout<<ans<<endl;
}
