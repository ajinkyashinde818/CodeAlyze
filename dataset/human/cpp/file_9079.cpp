#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"
#include "map"

using namespace std;
const long long int MOD = 1000000007;

int N,M;
char letter[2][100][100];
int ans;
bool flag;


int main() {
	cin >> N>>M;
	for (int i = 0; i < N; i++) {
		cin >> letter[0][i];
	}
	for (int j = 0; j < M; j++) {
		cin >> letter[1][j];
	}
	for (int i = 0; i <= N - M; i++) {
		for (int j = 0; j <= N - M; j++) {
			flag = true;
			for (int k = 0; k < M; k++) {
				for (int l = 0; l < M; l++) {
					if (letter[0][i+k][j+l] != letter[1][k][l]) {
						flag = false;
					}
				}
			}
			if (flag)ans++;
		}
	}
	if (ans)cout << "Yes\n";
	else cout << "No\n";

	return 0;
}
