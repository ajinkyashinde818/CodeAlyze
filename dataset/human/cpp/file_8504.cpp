#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> P;
const int c_INF = 111111111;
const int c_mINF = -111111111;
const int c_YET = -1;
const int c_Dx[4] = { 0,0,1,-1 };
const int c_Dy[4] = { 1,-1,0,0 };
const int c_div = 1000000007; //10^9 + 7


int main() {
	int N,M;
	scanf("%d%d", &N, &M);
	char A[100][100],B[100][100];
	for (int i = 0; i < N; i++) {
		scanf("%s", A[i]);
	}
	for (int i = 0; i < M; i++) {
		scanf("%s", B[i]);
	}


	bool in = false;



	for (int i = 0; i < N - M +1; i++) {
		for (int j = 0; j < N - M+1; j++) {
			
			bool temp = true;
			for (int x = 0; x < M; x++) {
				for (int y = 0; y < M; y++) {
					
					if (A[i + x][j + y] != B[x][y]) {
						temp = false;
						break;
					}
				}
			}

			if (temp) {
				printf("Yes");
				return 0;
			}

		}
	}


	printf("No");






}
