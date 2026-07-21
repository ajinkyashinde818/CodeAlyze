#include <iostream>
#include <string>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    string A[50],B[50];
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    for(int i=0;i<M;i++){
        cin >> B[i];
    }

    for(int i=0;i<=N-M;i++){
        for(int j=0;j<=N-M;j++){
            bool flg=true;
            for(int h=0;h<M;h++){
                if(A[i+h].substr(j,M)!=B[h]) flg=false;
            }

            if(flg){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
