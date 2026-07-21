#include <bits/stdc++.h>
using namespace std;

const int MAXN = 51;

char A[MAXN][MAXN];
char B[MAXN][MAXN];

int main(){
    ios_base::sync_with_stdio(false);
	int N, M; cin >> N >> M;
	assert(M <= N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> A[i][j];

	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= M; j++)
			cin >> B[i][j];
			
	for (int i = 1; i <= N - M + 1; i++){
		for (int j = 1; j <= N - M + 1; j++){
			bool ok = true;
			for (int p = i; p < i + M; p++){
				for (int q = j; q < j + M; q++){
					if (A[p][q] != B[p - i + 1][q - j + 1]){
						ok = false; break;
					}
				} 
			}
			if (ok){
				cout << "Yes"; return 0;
			}
		}
	}
	cout << "No";
    return 0;
}
