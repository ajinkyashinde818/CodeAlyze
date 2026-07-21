#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	cin>>n;
	ll sum1=0,sum2=0;
	int cnt1=0,cnt2=0;
	vector<int>arr(n+1);
	for(int i=1; i<=n; i++){
		cin>>arr[i];
		if(arr[i]==0)
		 cnt1++;
		else if(arr[i]<0){
			cnt2++;
			sum1+=(-arr[i]);
		}
		else
		 sum2+=arr[i];
	}
	if(cnt2%2==0){
		cout<<sum2+sum1;
	}
	else if(cnt1){
		cout<<sum2+sum1;
	}
	else{
		int mn1=1e5,mn2=1e5;
		for(int i=1; i<=n; i++){
			if(arr[i]<0){
				mn1=min(mn1,-arr[i]);
			}
			else
			 mn2=min(mn2,arr[i]);
		}
		if(mn1>mn2){
			cout<<sum2+sum1-2*mn2;
		}
		else
		 cout<<sum1+sum2-2*mn1;
	}
	
	return 0;
	
}
