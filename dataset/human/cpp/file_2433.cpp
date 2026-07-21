#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<numeric>
#include<map>
using namespace std;

int main(){
    int N,A[100010];
    cin>>N;
    for(int i=0;i<N;++i)cin>>A[i];

    long long dp[100010][2];

    dp[2][0]=max(A[0]+A[1],-A[0]-A[1]);
    dp[2][1]=max(A[0]-A[1],-A[0]+A[1]);

    for(int n=3;n<=N;++n){
        dp[n][0]=max(dp[n-1][0]+A[n-1],dp[n-1][1]-A[n-1]);
        dp[n][1]=max(dp[n-1][0]-A[n-1],dp[n-1][1]+A[n-1]);
    }
    cout<<dp[N][0]<<endl;
    return 0;
}
