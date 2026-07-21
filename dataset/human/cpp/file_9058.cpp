#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    string S[50],T[50];
    int N,M;
    cin >> N >> M;
    for(int i=0;i<N;i++)cin >> S[i];
    for(int i=0;i<M;i++)cin >> T[i];
    int isFalse =0;
    for(int i=0;i<=N-M;i++){
        isFalse = 0;
        for(int j=0;j<=N-M;j++){
            isFalse=0;
            for(int k=0;k<M && isFalse==0;k++){
                for(int m=0;m<M && isFalse==0;m++){
                    if(S[i+k][j+m] != T[k][m])isFalse=1;
                
                }                
            }
            if(isFalse==0){
            cout << "Yes";
            return 0;
            }
        }
        
    }
    cout << "No";
    return 0;
    
}
