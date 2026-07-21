#include<iostream>
#include<string>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	string A[50], B[50];
	for (int i = 0; i < N; i++)cin >> A[i];
	for (int i = 0; i < M; i++)cin >> B[i];
	bool flag = false;
	for (int i = 0; i < N; i++) {
		for (int i2 = 0; i2< N; i2++) {
			for (int j = 0; j < M; j++) {
				for (int j2 = 0; j2 < M; j2++) {
					if (A[i+j][i2+j2] != B[j][j2]) goto search_stop;
					if (j == M - 1 && j2 == M - 1)flag = true;
				}
			}
		search_stop:;
		}
	}
	if (flag)cout << "Yes" << endl;
	else cout << "No" << endl;
}
