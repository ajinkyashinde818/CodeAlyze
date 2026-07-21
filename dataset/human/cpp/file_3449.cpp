#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	long long arr[n];
	long long cntneg=0;
	long long sum=0;
	long long mini=INT_MAX;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		if(arr[i]<0) cntneg++;
		sum+=abs(arr[i]);
		mini=min(mini,abs(arr[i]));
	}
	if(cntneg%2==0)cout<<sum;
	else cout<<sum - ((2*1LL)* mini);
	return 0;
}
