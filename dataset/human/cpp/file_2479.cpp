#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

int main()
{
	int *a;
	int n, cnt;
  	long long int sum, min;
	cnt = 0;
	sum = 0;
	min = 100000;
	
	cin >> n;
	a = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < 0) {
			cnt++;
		}
		
		if (abs(a[i]) < min) {
			min = abs(a[i]);
		}
	}
	
	if (cnt%2) {
		for (int i = 0; i < n; i++) {
			sum += abs(a[i]);
		}
      	sum = sum - 2*min;
	} else {
		for (int i = 0; i < n; i++) {
			sum += abs(a[i]);
		}
	}
	
	cout << sum;
	

    return 0;
}
