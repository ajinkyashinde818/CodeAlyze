#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	long long arr[n];
	long long sum=0;
	for (int i=0; i<n; i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	long long diff = 100000000000;
	long long sum1=0;
	for (int i=0; i<n-1; i++){
		sum1+=arr[i];
		diff = min(diff, abs(sum1-(sum-sum1)));
	}
	cout << diff << endl;

}
