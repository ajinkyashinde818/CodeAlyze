#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
	cin>>n;
	long long arr[n];
	long long ans=0;
	for(int y=0;y<n;y++)
		cin>>arr[y];

	long long cnt=0,min__=INT_MAX;
	for(int y=0;y<n;y++)
	{
		if(arr[y]!=abs(arr[y]))
			cnt++;
		min__=min(abs(arr[y]),min__);
		//	cout<<arr[y]<<" ";
	}
	for(int y=0;y<n;y++)
	{
		ans+=abs(arr[y]);
	}
	if(cnt%2==0)
		cout<<ans<<endl;
	else
		cout<<ans-2*min__<<endl;
	return 0;
}
