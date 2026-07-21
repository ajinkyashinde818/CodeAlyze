#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int64_t> A(N);
    for(auto &a:A) cin>>a;
    int64_t dp[2][N];//0:+, 1:-
    dp[0][1]=A[0]+A[1];
    dp[1][1]=-dp[0][1];
    for(int i=1;i<N-1;i++){
        dp[0][i+1]=max(dp[0][i],dp[1][i])+A[i+1];
        dp[1][i+1]=max(dp[0][i]-2*A[i]-A[i+1],dp[1][i]+2*A[i]-A[i+1]);
    }
    cout<<max(dp[0][N-1],dp[1][N-1])<<endl;

    return 0;
}
