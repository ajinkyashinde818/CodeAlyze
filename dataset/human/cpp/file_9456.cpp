#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string A[50];
string B[50];


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for(int i = 0; i < M; i++) {
		cin >> B[i];
	}

	bool ans = false;
	for(int i = 0; i <= N - M; i++) {
		for(int j = 0; j <= N - M; j++) {
			bool ok = true;
			for(int k = 0; k < M; k++) {
				if(A[i + k].substr(j, M) != B[k]) {
					ok = false;
					break;
				}
			}
			if(ok) ans = true;
		}
	}

	if(ans) cout << "Yes" << endl;
	else cout << "No" << endl;
}
