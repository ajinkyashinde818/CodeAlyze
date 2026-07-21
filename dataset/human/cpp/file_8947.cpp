#include <iostream>
#include <string>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    char A[N][N], B[M][M];
    string a, b;
    for (int i=0; i<N; i++){
        cin >> a;
        for (int j=0; j<N; j++){
            A[i][j] = a[j];
        }
    }
    for (int i=0; i<M; i++){
        cin >> b;
        for (int j=0; j<M; j++){
            B[i][j] = b[j];
        }
    }

    bool ok;
    for (int l1=0; l1<N-M+1; l1++){
        for (int l2=0; l2<N-M+1; l2++){
            ok = true;
            for (int i=0; i<M; i++){
                for (int j=0; j<M; j++){
                    if (A[l1+i][l2+j] != B[i][j]){
                        ok = false;
                    }
                }
            }
            if (ok){
                break;
            }
        }
        if (ok){
            break;
        }
    }
    if (ok){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
