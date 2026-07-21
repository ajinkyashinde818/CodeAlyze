#include <iostream>
#include <algorithm>

using namespace std;

int num[100000];

int main(){
	int n;
	cin >> n;

	int sign = 1;
	int64_t sum = 0;

	for(int i = 0; i < n; ++i){
		int tmp;
		cin >> tmp;
		if(tmp < 0){
			sign *= -1;
			tmp *= -1;
		}
		num[i] = tmp;
		sum += tmp;
	}

	sort(num, num+n);

	if(sign < 0){
		sum -= 2*num[0];
	}

	cout << sum << endl;

	return 0;
}
