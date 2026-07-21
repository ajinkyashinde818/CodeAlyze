#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    char A[N][N],B[M][M];
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        strcpy(A[i], s.c_str());
    }
    for(int i=0;i<M;i++){
        string s;
        cin >> s;
        strcpy(B[i], s.c_str());
    }
    //int a = N%M==0 ? N/M : N/M+1;
    bool b = true;
    for(int i=0;i<N-M+1;i++){
        for(int j=0;j<N-M+1;j++){
            b=true;
            for(int k=0;k<M;k++){
                for(int l=0;l<M;l++){
                    if(A[i+k][j+l]!=B[k][l]){
                        b=false;
                        goto OUT;
                    }
                }
            }
            OUT:
            if(b) {
                cout << "Yes" << endl;
                goto END;
            }
        }
    }
    END:
    if(!b) cout << "No" << endl;
    return 0;
}
