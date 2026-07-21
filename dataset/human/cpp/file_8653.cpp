#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){ 
    int N,M; cin >> N >> M;
    char A[N][N],B[M][M];
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++) cin >> A[i][j];
    }
    for (int i=0;i<M;i++){
        for (int j=0;j<M;j++) cin >> B[i][j];
    }

    string ans = "No";
    for (int l=0;l<N-M+1;l++){
        for (int k=0;k<N-M+1;k++){
            bool tmp = true;
            for (int i=0;i<M;i++){
                for (int j=0;j<M;j++){
                    if (A[i+k][j+l]!=B[i][j]){
                        tmp = false;
                        break;
                    }
                }
                if (!tmp) break;
            }
            if (tmp) {
                ans = "Yes";
                break;
            } 
        }
        if (ans=="Yes") break;
    }
    cout << ans << endl;
}
