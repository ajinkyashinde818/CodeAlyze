#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void){
	int n;

	cin >> n;

	vector<long long int> a(n);

	long long int sum = 0;
	
	for (int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}

	long long int tempsum = 0;


	long long int m = 10000000000000;
	for (int i = 0; i < n - 1; i++){
		tempsum += a[i];
		m = min(m, abs(2*tempsum-sum));
	}


	cout << m << endl;



}
