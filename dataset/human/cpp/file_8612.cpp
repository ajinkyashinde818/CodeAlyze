#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int N, M, i, j, k, l, judge=1, ans=0;
    string A[52], B[52];

    cin >> N >> M;

    for(i=0; i<N; i++){
        cin >> A[i];
    }

    for(i=0; i<M; i++){
        cin >> B[i];
    }

    for(i=0; i<=N-M; i++){
        for(j=0; j<=N-M; j++){ // Aの中を移動
            judge = 1;

            for(k=0; k<M; k++){
                for(l=0; l<M; l++){
                    if(A[i+k][j+l] != B[k][l]){
                        judge = 0;
                    }
                }
            }

            if(judge == 1){
                ans = 1;
            }
        }
    }

    if(ans == 1){
        cout << "Yes" << endl;
    }

    else{
        cout << "No" << endl;
    }

    return 0;
}
