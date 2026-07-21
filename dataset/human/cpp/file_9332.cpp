#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<vector<char> > A(N, vector<char>(N));
    vector<vector<char> > B(M, vector<char>(M));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < M; j++) {
            cin >> B[i][j];
        }
    }

    for(int i = 0; i <= N - M; i++) {
        for(int j = 0; j <= N - M; j++) {
            bool checker = false;
            for(int k = 0; k < M; k++) {
                for(int l = 0; l < M; l++) {
                    if(B[k][l] != A[i + k][j + l]) {
                        checker = true;
                        break;
                    }
                }
                if(checker) break;
            }
            if(checker) continue;

            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}
