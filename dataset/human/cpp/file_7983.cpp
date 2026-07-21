#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(void){
	int i, n, j, k=0, flag=0;
	long long min = 0, z = 0;
	long long sum_sn = 0, sum_ar = 0;
	vector<int> a(200001);

	cin >> n;

	a[0] = 0;
	
	for (i = 1; i <= n; i++){
		cin >> a[i];
	}

	for (i = 1; i <= n; i++){
		sum_ar += a[i];
	}
	sum_sn += a[1];
	sum_ar -= a[1];
	min = abs(sum_sn - sum_ar);

	for (i = 2; i < n; i++){
		sum_sn += a[i];
		sum_ar -= a[i];
		z = abs(sum_sn - sum_ar);
		if (z < min) min = z;
	}
	cout << min << endl;

	return 0;
}
