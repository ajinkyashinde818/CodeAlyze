#include<iostream>

using namespace std;

long long  n,a[200000],mysum,ans=1e20,x,y;

long long ze(long long i){
	if(i>=0) return i;
	else return -1*i;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mysum+=a[i];
	}
	for(int i=0;i<n-1;i++){
		x+=a[i];
		y=mysum-x;
		long long nowans;
		nowans=ze(x-y);
		if(ans>=nowans) ans=nowans;
	}
	cout<<ans<<endl;
	return 0;
}
