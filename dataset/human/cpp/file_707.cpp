#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <iomanip>
#include <vector>

using namespace std;

int main(){
	uint16_t R, G, B, N;
	cin >> R >> G >> B >> N;
	uint32_t res = 0;
	for(uint16_t r = 0;r <= N / R;++r){
		for(uint16_t g = 0;g <= (N - (R * r)) / G;++g){
			if(((N - (R*r)) - (G*g)) % B == 0)
				++res;
		}
	}

	cout << res << endl;

	return 0;
}
