#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<cstring>
#include<unordered_map>
#include<unordered_set>
#include<tuple>
#include<vector>
#include<cmath>


using namespace std;

unordered_set <int> Good;

const int MAXN = 100000 + 10;
int cnt[MAXN];


const int MAXK = 500;
int board[MAXK][MAXK];

int main() {
	int N;
	cin >> N;
	
	for (int i = 1; i < 500; i++) {
		Good.insert(i * (i + 1) / 2);
	}

	if (!Good.count(N)) cout << "No" << endl;
	else {
		cout << "Yes" << endl;
		int K = (int)sqrt(N * 2) + 1;
		int Q = N * 2 / K;
		int cur = 1;
		cout << K << endl;
		for (int i = 0; i < K; i++) {
			cout << Q << " ";
			for (int j = 0; j < i; j++) {
				cout << board[j][i - 1] << " ";
				board[i][j] = board[j][i - 1];
			}

			for (int k = i; k < Q; k++) {
				cout << cur << " ";
				board[i][k] = cur++;
			}
			cout << endl;
		}
	}

	return 0;
}
