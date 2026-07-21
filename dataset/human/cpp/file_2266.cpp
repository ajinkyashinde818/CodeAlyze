#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<long long> v(n);
	long long cnt=0;
	for(long long i=0;i<n;i++){
		cin>>v[i];
		if(v[i]<0){
			cnt++;
			v[i]=abs(v[i]);
		}
	}
	sort(v.begin(),v.end());
	long long ans=0;
	for(long long i=0;i<n;i++)ans+=v[i];
	cnt=cnt%2;
	if(cnt)ans=ans-v[0]*2;
	cout<<ans<<endl;
	return 0;
}
