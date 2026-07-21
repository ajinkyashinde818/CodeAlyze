#include <bits/stdc++.h>
using namespace std;
int n,i;
long long int a[200001],x,y,sum=0;
int main(void)
{
	cin >> n;
	for(i=0;i<n;i++){
		cin >> a[i];
		y+=a[i];
	}
	x=a[0];
	y-=a[0];
	sum=llabs(x-y);
	for(i=1;i<n-1;i++){
		x+=a[i];
		y-=a[i];
		if(llabs(x-y)<sum)sum=llabs(x-y);	
	}
	cout << sum << endl;
	return 0;
}
