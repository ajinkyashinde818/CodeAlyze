#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,i,x,cnt=0,ans=0,mi=INT_MAX;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>x;
		if(x<0){
			cnt++;
		}
		mi=min(abs(x),mi);
		ans+=abs(x);
	}
	if(cnt%2){
		cout<<ans-mi-mi<<endl;
	}
	else{
		cout<<ans<<endl;
	}
	return 0;
}
