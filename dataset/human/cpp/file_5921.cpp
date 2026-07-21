#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main(void){
	long long int n, c;
	static long long int dpc[100001] = {}, dpi[100001] = {};
	cin >> n >> c;

	vector<long long int> x(n + 2), v(n + 1);

	for (int i = 1; i < n + 1; i++){
		cin >> x[i] >> v[i];
	}

	x[0] = 0;
	v[0] = 0;
	x[n+1] = c;

	long long int m = 0;
	long long int sum = 0;

	//clockwise
	for (int i = 1; i < n + 1; i++){
		sum = sum + v[i] - (x[i] - x[i-1]);
		dpc[i] = max(sum, dpc[i-1]);
		m = max(m, sum);
	}

	//inverse
	sum = 0;
	for (int i = n; i >= 1; i--){
		sum = sum + v[i] - (x[i+1] - x[i]);
		m = max(m, sum);
		dpi[i] = max(sum, dpi[i+1]);
	}

	for (int i = 1; i < n + 1; i++){
		sum = 0;
/*		for (int j = 1; j <= i; j++){
			sum = sum + v[j] - (x[j] - x[j-1]);
		}*/

		m = max(m, dpc[i] + dpi[i+1] - x[i]);
	}

	for (int i = 1; i < n + 1; i++){
		sum = 0;
/*		for (int j = n; j >= i; j--){
			sum = sum + v[j] - (x[j+1] - x[j]);
		}*/
		m = max(m, dpi[i] + dpc[i-1] - (c - x[i]));
	}


	cout << m << endl;
}
