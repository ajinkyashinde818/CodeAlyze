#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
 int a[3],n;
 cin>>a[0]>>a[1]>>a[2]>>n;
 ll dp[4][n+1];
 for(ll i=0;i<=n;i++) dp[3][i]=0;
 dp[3][0]=1;
 for(int i=2;i>=0;i--){
  for(int j=0;j<=n;j++){
   dp[i][j]=0;
   for(int k=0;k*a[i]<=j;k++){
     dp[i][j]+=dp[i+1][j-k*a[i]];
   }
  }
 }
 cout<<dp[0][n]<<endl;
 return 0;
}
