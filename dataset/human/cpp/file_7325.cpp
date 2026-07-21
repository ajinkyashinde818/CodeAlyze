#include<iostream>
#include<cmath>
using namespace std;
long long abs1(long long a){
	if(a>0)return a;
	else return -a;
}
int main(){
	long long n,a[200051],sum=0,he=0,ans=1111111111111111111;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
}
for(int i=1;i<n;i++){
	he+=a[i];
	ans=min(ans,abs1(sum-2*he));
}
cout<<ans;
}
