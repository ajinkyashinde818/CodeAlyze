#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main(){
	long long a,i,n, Sum=0, min;
	cin >> n;
	vector <long long> sum(n);

	for (i=0; i<n-1; i++){
		cin >>a;
		Sum += a;
		sum[i] = Sum;
	}
	cin >> a;
	Sum += a;
	// cout << "Sum=" << Sum << endl;
	
	min = abs(2*sum[0] - Sum);
	for(i=1; i<n-1; i++){
		sum[i] = abs(2*sum[i] - Sum);
		// cout << "sum[i]=" << sum[i] << endl;
		if (sum[i] < min){
			min = sum[i];
		}
	}
	cout << min << endl;

	return 0;
}
