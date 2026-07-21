#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,c=0;
	cin>>n;
	long long a[n],m=1e9+8;
	long long int s=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]<0) c++;
		m=min(m,abs(a[i]));
		s+=abs(a[i]);
	}
	if (c%2==1)
	{
		cout<<s-2*m;
	}
	else
	{
		cout<<s;
	}
	
	return 0;
}
