#include <bits/stdc++.h>
using namespace std;

const string YES = "Yes";
const string NO = "No";

void solve(long long N, long long M, std::vector<std::string> A, std::vector<std::string> B){

    for(long long i = 0; i <= N - M; ++i){
        for(long long j = 0; j <= N - M; ++j){
            bool flag = true;
            for(long long k = i; k < i + M; ++k){
                //cout << "B: " << B[k-i] << endl;
                //cout << "A: " << A[k].substr(j, M) << endl;
                if(A[k].substr(j, M) != B[k-i]) flag = false;
            }
            //cout << flag << endl;
            if(flag){
                cout << YES << endl;
                exit(0);
            }
        }
    }
    cout << NO << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<std::string> A(N);
    for(int i = 0 ; i < N ; i++){
        std::cin >> A[i];
    }
    std::vector<std::string> B(M);
    for(int i = 0 ; i < M ; i++){
        std::cin >> B[i];
    }
    solve(N, M, std::move(A), std::move(B));
    return 0;
}
