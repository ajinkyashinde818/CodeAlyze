#include <iostream>
#include <algorithm>
using namespace std;
 
const long long INF=11111111111;
const int N=2*1e5+10;
long long a[N];

long long MM(long long a,long long b){
	return a>b ? b : a;
}

int main(){
	int n;
	long long sum=0,tmp=0;
	cin>>n;	
	for(int i=1;i<=n;i++) {cin>>a[i];sum+=a[i];}
	long long ans=INF;
	for(int i=1;i<n;i++){
		tmp+=a[i];
		ans=MM(ans,abs(2*tmp-sum));
	}
	cout<<ans<<endl;
	return 0;
}
