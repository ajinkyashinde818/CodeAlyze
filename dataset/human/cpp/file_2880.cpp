#include<iostream>
using namespace std;

int main()
{
	int n;
	long a[100000];
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	
	int v=0;
	long minv=labs(a[0]),sum=0;
	for(int i=0;i<n;i++){
		if(a[i]<0) v++;
		if(labs(a[i])<minv) minv=labs(a[i]);
		sum+=labs(a[i]);
	}
	
	cout<<((v%2)? sum-2*minv:sum)<<endl;
	
	return 0;
}
