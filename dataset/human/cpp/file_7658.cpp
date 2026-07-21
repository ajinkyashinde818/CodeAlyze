#include<iostream>
#include<algorithm>
using namespace std;


int main(){
	long long n;
	int a[200100];
	long long X = 0;
	long long sum = 0;
	long long res = 1000000000000000;

	cin>>n;

	for(int i = 0; i < n; i++){
		cin>>a[i];
		sum += a[i];
	}


	for(int i = 0;i<n-1;i++){
		X += a[i];
		long long A = sum - X;
		res = min(res,abs(X-A));
	}

	cout<<res<<"\n";

}
