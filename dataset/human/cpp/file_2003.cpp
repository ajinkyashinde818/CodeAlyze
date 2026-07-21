#include<bits/stdc++.h>
using namespace std;
int main(){
  long N;
  cin>>N;
  vector<long> A(N);
  for(int i=0;i<N;i++)cin>>A[i];
  long dp[1<<17][2];
  dp[0][0]=0;
  dp[0][1]=-(1L<<60);
  for(int i=0;i<N;i++){
    dp[i+1][0]=max(dp[i][0]+A[i],dp[i][1]-A[i]);
    dp[i+1][1]=max(dp[i][0]-A[i],dp[i][1]+A[i]);
  }
  cout<<dp[N][0]<<endl;
  return 0;
}
