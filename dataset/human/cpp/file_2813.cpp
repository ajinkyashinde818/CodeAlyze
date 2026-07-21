#include<bits/stdc++.h>

using namespace std;
const int N = 1e6+100;
long long a[N];
int main(){
	int n;
	cin>>n;
	int num=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<0) num++;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		a[i]=abs(a[i]);
		ans+=a[i];
	}
	sort(a+1,a+n+1);
	if(num&1){
		cout<<ans-2*a[1]<<endl;
	}
	else{
		cout<<ans<<endl;
	}
	return 0;
}
