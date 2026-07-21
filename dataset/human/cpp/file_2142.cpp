#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	cin>>n;
	int cnt=0;
	long long mi=INT_MAX,sum=0;
	while(n--){
		long long x;
		cin>>x;
		sum+=abs(x);
		if(x<0){
			cnt++;
		}
		x=abs(x);
		mi=min(mi,x);
	}
	if(cnt%2==1){
		sum-=(mi*2);
	}
		cout<<sum<<endl;
}
