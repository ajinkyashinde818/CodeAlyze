#include<iostream>

using namespace std;

string A[55],B[55];
int N,M;
int main () {
    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<M; i++) cin >> B[i];

    if( M > N ) {
        cout << "No" << endl;
        return 0;
    }
    for(int i=0; i<=N-M; i++) {
        for(int j=0; j<=N-M; j++) {
            bool flag = true;

            for(int k=0; k<M; k++) {
                for(int m=0; m<M; m++) {
                    if( A[k+i][m+j] != B[k][m] ) flag = false;
                }
            }
            if( flag ) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
