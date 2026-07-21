#include <bits/stdc++.h>
using namespace std;

int main () {
	
	long long int n = 0, x=0, i=0, zero=0, aux=0, res=0;
	vector <long long int> nums, sign;

	cin >> n;

	long long int chico = INT_MAX;
	for (i=0; i<n; i++) {
		cin >> x;
		nums.push_back(abs(x));
		chico = min(chico, abs(x));
		if (x >= 0) sign.push_back(1);
		else sign.push_back(-1);
	}

	int t = nums.size();

	for (i=0; i<n-1; i++) {
		if (sign[i] == -1 && nums[i] != 0) {
			sign[i] *= -1;
			sign[i+1] *= -1;
		}
	}

	if (sign[t-1] == -1) {
		if (chico != nums[t-1]) {
			sign[t-1] *= -1;

			for (i=0; i<n; i++) {
				if (nums[i] == chico) {
					sign[i] *= -1;
					break;
				}
			}
		}

	}

	for (i=0; i<n; i++) res += nums[i]*sign[i];

	
	cout << res << endl;

	return 0;
}

//11
//-1000000000 1000000000 -1000000000 1000000000 -1000000000 0 1000000000 -1000000000 1000000000 -1000000000 1000000000
//10000000000
