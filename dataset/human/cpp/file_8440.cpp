#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<string> A(N);
    vector<string> B(M);
    for(int n=0; n<N; n++) {
        cin >> A[n];
    }
    for(int m=0; m<M; m++) {
        cin >> B[m];
    }
    
    bool flag=false;
    for(int ni=0; ni<N-M+1; ni++) {
        for(int nj=0; nj<N-M+1; nj++) {
            bool tmpf=true;
            for(int mi=0; mi<M; mi++) {
                for(int mj=0; mj<M; mj++) {
                    if(A[ni+mi][nj+mj]!=B[mi][mj]) {
                        tmpf=false;
                        break;
                    }
                }
                if(!tmpf) {
                    break;
                }
            }
            if(tmpf) {
                flag=true;
                break;
            }
        }
        if(flag) {
            break;
        }
    }
    
    if(flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


    return 0;
    
}
