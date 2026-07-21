#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, M, i, j, k, l;
	scanf("%d%d", &N, &M);
	vector<string> A(N), B(M);
	for(i = 0; i < N; i++){
		cin >> A[i];
	}
	for(i = 0; i < M; i++){
		cin >> B[i];
	}
	for(i = 0; i + M <= N; i++){
		for(j = 0; j + M <= N; j++){
			int f = 1;
			for(k = 0; k < M; k++){
				for(l = 0; l < M; l++){
					if(A[i + k][j + l] != B[k][l]){
						f = 0;
					}
				}
			}
			if(f == 1){
				printf("Yes\n");
				return 0;
			}
		}
	}
	printf("No\n");
	return 0;
}
