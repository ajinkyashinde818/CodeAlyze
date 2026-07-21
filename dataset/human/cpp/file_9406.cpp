#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int M, N;
    cin >> N >> M;
    vector<string> A(N), B(M);
    for ( int i = 0; i < N; i++ ) cin >> A.at(i);
    for ( int i = 0; i < M; i++ ) cin >> B.at(i);

    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < N; j++ ) {
            bool found = true;
            for ( int k = 0; k < M; k++ ) {
                for ( int l = 0; l < M; l++ ) {
                    if ( i + k >= N || j + l >= N ) {
                        found = false;
                        break;
                    }
                    if ( A.at(i+k).at(j+l) != B.at(k).at(l) ) {
                        found = false;
                        break;
                    }
                }
                if ( !found ) break;
            }
            if ( found ) goto FOUND;
        }
    }

    cout << "No" << endl;
    return 0;
FOUND:
    cout << "Yes" << endl;
    return 0;
}
