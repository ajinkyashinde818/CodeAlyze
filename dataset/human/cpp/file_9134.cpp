#include<bits/stdc++.h>

using namespace std;

int main(){
	int N, M; cin >> N >> M;
	char A[N][N];
	char B[M][M];
	for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) cin >> A[i][j];
	for(int i = 0; i < M; ++i) for(int j = 0; j < M; ++j) cin >> B[i][j];

	for(int i = 0; i < N-M+1; ++i){
		for(int j = 0; j < N-M+1; ++j){
			bool isSame = true;
			for(int k = 0; k < M; ++k){
				for(int l = 0; l < M; ++l){
					int nowx = l + j;
					int nowy = k + i;
					if(A[nowy][nowx] != B[k][l]){
						isSame = false;
						break;
					}
				}
				if(!isSame) break;
			}
			if(isSame){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
}
