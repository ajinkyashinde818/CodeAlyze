#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
int main(void){
	ll n,i,sum=0,ans,res;
	cin>>n;
	ll a[n];
	for(i=0;i<n;i++){cin>>a[i];sum+=a[i];}
	sum-=a[0];
	res=a[0];
	ans=abs(res-sum);
	for(i=1;i<n-1;i++){
		sum-=a[i];
		res+=a[i];
		ans=min(ans,abs(res-sum));
	}
	cout<<ans<<endl;
	return 0;
}
