#include<iostream>
#include<string>
#include<algorithm>
#include<set>
using namespace std;
using ll = long long;
int main() {
	int N, M; cin >> N >> M;
	string A[50], B[50];
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < M; i++)
		cin >> B[i];

	bool exist = true;
	for (int i = 0; i + M <= N; i++) {
		for (int j = 0; j + M <= N; j++) {
			if (A[i][j] == B[0][0]) {
				exist = true;
				for (int k = 0; k < M; k++) {
					if (A[i + k].substr(j, M) != B[k]) {
						exist = false;
						break;
					}
				}
				if (exist) {
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}
	cout << "No" << endl;

	//system("pause");
	return 0;
}
