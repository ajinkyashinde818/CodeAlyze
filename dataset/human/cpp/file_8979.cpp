#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    string A[50], B[50];
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];
    int num = N-M+1;
    bool f = false;
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){

            f = false;
            for(int a = 0; a < M; a++){
                for(int b = 0; b < M; b++){
                    if(A[a+i][b+j] == B[a][b]) f= true;
                    else {f = false; break;}
                }
                if(!f) break;
            }
            
            if(f) break;
        }
        if(f) break;
    }
    cout << (f ? "Yes" : "No") << endl;
}
