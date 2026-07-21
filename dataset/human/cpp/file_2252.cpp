//
// Created by yuu on 2019-04-27.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <math.h>
#include <stack>
#include <queue>

using namespace std;

long long dp[2][100100]={};

long A[1000100];
int main(void){
    int N;
    cin>>N;
    for (int i = 0; i < N; ++i) {
        cin>>A[i];
    }

    for (int i = 0; i < N-1; ++i) {
            if(i==0){
                dp[0][i] = A[i] + A[i+1];
                dp[1][i] = -1 * A[i] + -1*A[i+1];
                continue;
            }

            dp[0][i] = max(dp[0][i-1] + A[i+1], dp[1][i-1] + A[i+1]);
            dp[1][i] = max(dp[0][i-1] + -1*A[i+1] + -1*2*A[i], dp[1][i-1] + -1*A[i+1] + 1*2*A[i]);
//            cout<<"-1*A[i] ="<<-1*A[i]<<endl;
    }

//    for (int j = 0; j < N; ++j) {
//        cout<<dp[0][j]<<",,"<<dp[1][j]<<endl;
//    }

    cout<<max(dp[0][N-2],dp[1][N-2])<<endl;


    return 0;
}
