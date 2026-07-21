#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(void){
    int N,M;
    cin >> N >> M;
    string A[N],B[M];
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    for(int i=0;i<M;i++){
        cin >> B[i];
    }
    for(int H=0;H+M-1<N;H++){
        for(int W=0;W+M-1<N;W++){
            bool OK = true;
            for(int i=0;i<M;i++){
                if(!OK)break;
                for(int j=0;j<M;j++){
                    if(B[i][j] != A[H+i][W+j]){
                        OK = false;
                        break;
                    }
                }
            }
            if(OK){
                cout << "Yes" << endl;
                return 0;
            }
            
        }
        
    }
    cout << "No" << endl;
}
