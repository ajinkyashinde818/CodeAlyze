#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x;
	long long sum=0;
	scanf("%d",&n);
	int f=0,mn=1e9+1;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(x<0)
			f++;
		sum+=abs(x);
		mn=min(mn,abs(x));
	}
	if(f%2==1)
		sum-=2*mn;
	printf("%lld\n",sum);
}
