#include<iostream>
#include<string>
#include<algorithm>


using namespace std;
bool match(int x, int y);
int N, M;
string A[60], B[60];

int main()

{
	bool can = false;
	cin	>> N >>M;
	
	for (int i = 0; i < N; ++i) cin >> A[i];
	for (int j = 0; j < M; ++j) cin >> B[j];

	for (int k = 0; k < N - M + 1; ++k) {
		for (int l = 0; l < N - M + 1; ++l) {
			if (match(k, l)) can = true;

		}
	}

	cout << (can ? "Yes":"No") << endl;
	return 0;

}

bool match(int x, int y) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			if (A[x + i][y + j] != B[i][j]) {
				return false;
			}
		}
		
	}
	return true;
}
