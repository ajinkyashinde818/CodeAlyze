#include <stdio.h>
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<complex>
#include<vector>

using namespace std;

const int INF = 1<<29;        // 十分大きい値にする, INT_MAX にしないのはオーバーフロー対策

int nx[]={0,1,0,-1};
int ny[]={0,1,0,-1};
//*****************************************
//方針：好きなだけ隣接２要素の符号反転をしてよいのである異なる２点の組を定めて、その組のみ符号反転させることが可能
//したがって負の要素があっても２つずつ正にしていくことができる
//最終的には負の要素が偶数の時は全て正、奇数の時は1つを残してすべて正にできる
//したがって偶数なら全絶対値合計、奇数なら負の数の絶対値最小のものを負にすることで総和を最大化できる
//今回は教育のためＤＰをつかって全てを探索していく

//i ∈ {0, 1, ..., N}, j ∈ {0, 1} に対して dp(i, j) を、A1, A2, ..., Ai を確定し、j = 1 なら i を選んで反転した
//場合 (すなわち Ai+1 の符号が反転している状態) の A1 + A2 + ... + Ai の最大値と定義します。
//dp[N][2]としてすべての要素を使う必要があるので答えはdp[N][0]である

//dp(i,0 or 1)がA1, A2, ..., Ai+1  と区間の総和最大値を表すことに注意

int main(void){

    int n,i;
    
    scanf("%d",&n);

    int A[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }

    long long dp[n][2];//dp[i][0]はA[i]の反転無し,dp[i][1]は-A[i]としたときの総和
    dp[0][0]=0;//要素なしの区間総和
    dp[0][1]=-INF;//存在しない

    for(i=0;i<n;i++)
    {
        dp[i+1][0]=max(dp[i][0]+A[i],dp[i][1]-A[i]);
        dp[i+1][1]=max(dp[i][0]-A[i],dp[i][1]+A[i]);
    }


    cout<<dp[n][0]<<endl;  
    return 0;
}
