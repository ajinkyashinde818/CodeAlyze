#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n, sum=0, neg=0, mini=1e9;
	cin  >> n;
	long long a[n+1];
	for(int i=0; i<n; i++){
		cin >> a[i];
		sum += abs(a[i]);
		if(a[i]<0) neg++;
		if(abs(a[i])<mini) mini = abs(a[i]);
	}

	if(neg %2 == 0)	cout << sum;
	else cout << sum - 2*mini;

    return 0;
}
