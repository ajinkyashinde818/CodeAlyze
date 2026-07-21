#include <bits/stdc++.h>
using namespace std;

void solve(long long N, long long M, vector<string> A, vector<string> B){
	for (int x = 0; x <= N - M; x++) {
    for (int y = 0; y <= N - M; y++) {
      bool matched = true;
      for (int j = 0; j < M; j++) {
        for (int k = 0; k < M; k++) {
          if (A[x+j][y+k] != B[j][k]) {
            matched = false;
            break;
          }
        }
        if (!matched) break;
      }

      if (matched) {
        cout << "Yes" << endl;
        return;
      }
    }
  }
  cout << "No" << endl;
}

int main(){	
	long long M;
	long long N;
	scanf("%lld",&N);
	vector<string> A(N-1+1);
	scanf("%lld",&M);
	vector<string> B(M-1+1);
	for(int i = 0 ; i <= N-1 ; i++){
		cin >> A[i];
	}
	for(int i = 0 ; i <= M-1 ; i++){
		cin >> B[i];
	}
	solve(N, M, A, B);
	return 0;
}
