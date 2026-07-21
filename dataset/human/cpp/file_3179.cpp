#include<bits/stdc++.h>
using namespace std; 
long long n,a,ans,f,x=1e9+7; 
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) 
	{
		cin>>a;
		if(a<=0) f++;
		ans+=abs(a);
		x=min(x,abs(a));
	}
	if(f%2==0) cout<<ans;
	else cout<<ans-x*2;
	return 0;
}
