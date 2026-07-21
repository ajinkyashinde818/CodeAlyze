#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n,x=0,y=0;
	cin>>n;
	long long a[n],b[n-1];
	for(long i=0;i<n;i++)cin>>a[i];
	x=a[0];
	for(long i=0;i<n;i++)y+=a[i];
	y-=a[0];
	for(long i=0;i<n-1;i++){
		b[i]=max(x-y,y-x);
		x+=a[i+1];
		y-=a[i+1];
	}
	sort(b,b +(n-1));
	cout<<b[0]<<endl;
	return 0;
}
