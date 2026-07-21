#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main(void){
	uint32_t N;
	int32_t *A;

	cin >> N;
	A = new int32_t[N];
	for(uint32_t i = 0;i < N;++i)
		cin >> A[i];

	uint32_t SignNum = 0;

	for(uint32_t i = 0;i < N;++i){
		if(A[i] < 0)
			++SignNum;		
	}

	int64_t res = 0;
	for(uint32_t i = 0;i < N;++i)
		res += abs(A[i]);

	if(SignNum & 0x01){
		int32_t Minimum = abs(A[0]), tmp;
		for(uint32_t i = 1;i < N;++i){
			tmp = abs(A[i]);
			if(tmp < Minimum)
				Minimum = tmp;
		}
		cout << setprecision(20) << res - (2 * Minimum) << endl;
	}else{
		cout << setprecision(20) << res << endl;
	}

	return 0;
}
