#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <array>
#include <vector>
#include <functional>
using namespace std;
 
int main(void) {
	int N, M, i, j, k, l, count = 0, flag = 0;
	cin >> N >> M;
	vector<vector<char>> NN(N, vector<char>(N));
	vector<vector<char>> MM(M, vector<char>(M));
 
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			cin >> NN[i][j];
	}
	for (i = 0; i < M; i++) {
		for (j = 0; j < M; j++)
			cin >> MM[i][j];
	}
 
	for (i = 0; i < N+1-M; i++){
		for (j = 0; j < N + 1 - M; j++) {
			count = 0;
			if (NN[i][j] == MM[0][0]) {
				for (k = 0; k < M; k++) {
					for (l = 0; l < M; l++) {
						if (NN[k+i][l+j] == MM[k][l]) {
							count++;
						}
					}
				}
			}
			if (count == M*M) {
				cout << "Yes" << endl;
				flag = 1;
				break;
			}
		}
		if (flag==1)break;
	}
	if (flag == 0)cout << "No" << endl;
	return 0;
}
