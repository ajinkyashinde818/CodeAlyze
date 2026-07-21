#include <iostream>
using namespace std;

int main() {
	long long n,c;cin>>n>>c;
	long long x[n],v[n],vsr[n],vsl[n];
	for(int i=0;i<n;i++){
		cin>>x[i]>>v[i];
	}
	long long maxkr[n];
	vsr[0]=v[0];
	maxkr[0]=vsr[0]-x[0];
	for(int i=1;i<n;i++){
		vsr[i]=vsr[i-1]+v[i];
		long long kr=vsr[i]-x[i];
		if(maxkr[i-1]<kr){
			maxkr[i]=kr;
		}else{
			maxkr[i]=maxkr[i-1];
		}
	}
	long long maxkl[n];
	vsl[n-1]=v[n-1];
	maxkl[n-1]=v[n-1]-(c-x[n-1]);
	for(int i=n-2;i>=0;i--){
		vsl[i]=vsl[i+1]+v[i];
		long long kl=vsl[i]-(c-x[i]);
		if(maxkl[i+1]<kl){
			maxkl[i]=kl;
		}else{
			maxkl[i]=maxkl[i+1];
		}
	}
	long long maxkr2[n],maxkl2[n];
	maxkr2[0]=v[0]-2*x[0];
	for(int i=1;i<n;i++){
		vsr[i]=vsr[i-1]+v[i];
		long long kr=vsr[i]-2*x[i];
		if(maxkr2[i-1]<kr){
			maxkr2[i]=kr;
		}else{
			maxkr2[i]=maxkr2[i-1];
		}
	}
	maxkl2[n-1]=v[n-1]-2*(c-x[n-1]);
	for(int i=n-2;i>=0;i--){
		vsl[i]=vsl[i+1]+v[i];
		long long kl=vsl[i]-2*(c-x[i]);
		if(maxkl2[i+1]<kl){
			maxkl2[i]=kl;
		}else{
			maxkl2[i]=maxkl2[i+1];
		}
	}
	long long ans=0;
	if(ans<maxkr[n-1])ans=maxkr[n-1];
	if(ans<maxkl[0])ans=maxkl[0];
	for(int i=0;i<n-1;i++){
		long long value=maxkr2[i]+maxkl[i+1];
		if(ans<value)ans=value;
		value=maxkr[i]+maxkl2[i+1];
		if(ans<value)ans=value;
	}
	cout<<ans<<endl;
//	for(int i=0;i<n;i++){
//		cout<<maxkr[i]<<endl;
//	}


	return 0;
}
