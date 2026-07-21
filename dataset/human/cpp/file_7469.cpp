#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
	int n;
	long long sum = 0;
	long long sub_sum = 0;
	long long min = INT_MAX;
	long diff;
	cin >> n;
	vector<long> v(n);
	for(int i = 0; i < n; i++) {
		long l;
		cin >> l;
		v[i] = l;
		sum += l;
	}
	for(int i = 0; i < n - 1; i++) {
		sub_sum += v[i];
		diff = abs(sum - 2*sub_sum);
		if(diff < min) min = diff;
	}
	cout << min;
	return 0;
}
