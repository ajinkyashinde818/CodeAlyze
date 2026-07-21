#include <iostream>

using namespace std;

int main(){
	int N[2];
	
	cin >> N[0] >> N[1];
	unsigned long long map[2][64];
	
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < N[i]; j++){
			char in[50];
			cin >> in;
			map[i][j] = 0;
			for (int k = 0; k < N[i]; k++){
				unsigned long long tmp = 1;
				if (in[k] == '#') map[i][j] = map[i][j] | (tmp<<k);
			}
		}
	}
	unsigned long long mask = 1;
	mask = (mask << N[1]);
	mask--;
	
	for (int i = 0; i <= (N[0] - N[1]); i++){
		for (int j = 0; j <= (N[0] - N[1]); j++){
			for (int k = 0; k < N[1]; k++){
				if (((map[0][i+k] & (mask << j)) != (map[1][k] << j))){break;}
				if (k == (N[1] - 1)) { cout << "Yes" << endl;  return 0; }
			}
		}
	}
	cout << "No" << endl;
	
	return 0;
}
