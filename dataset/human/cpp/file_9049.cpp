#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
    int N, M;
    cin >> N >> M;

    vector<string> A(N), B(M);
    for(int i{0}; i<N; ++i){
        cin >> A[i];
    }
    for(int i{0}; i<M; ++i){
        cin >> B[i];
    }

    for(int i{0}; i+M-1<N; ++i){
        for(int j{0}; j+M-1<N; ++j){
            bool flag{true};
            for(int k{0}; k<M; ++k){
                if(A[j+k].substr(i, M) != B[k]){
                    flag = false;
                    break;
                }
            }
             if(flag){
                 cout << "Yes" << endl;
                 return(0);
            }
        }
    }
    cout << "No" << endl;
}
