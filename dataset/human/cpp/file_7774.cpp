#include <iostream>
#include<math.h>
using namespace std;
long long int min(long long int a,long long int b)
{
	if(a<b)
	return a;
	else
	return b;
}
int main() {
	int n;
	cin>> n;
	int i;
	long long int arr[n];
	long long int sum=0;
	for(i=0;i<n;i++)
	{
		cin >> arr[i];
		sum+=arr[i];
	}
	long long int mini=10000000000;
	long long int cur=arr[0];
	sum-=arr[0];
	for(i=1;i<=n-1;i++)
	{
	mini=min(mini,abs(cur-sum));
	cur+=arr[i];
	sum-=arr[i];
	
	}
	cout << mini << endl;
	// your code goes here
	return 0;
}
