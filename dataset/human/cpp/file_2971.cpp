#include <iostream>

using namespace std;

int main(){

int n;
  cin >> n;
  
long dp[n+1][2];
  long a[n];
  
  dp[0][0]=0;
  dp[0][1]=-10000000000;
  
  for(int i=0;i<n;i++){
   cin >> a[i];
    
    dp[i+1][0]=max(dp[i][0]+a[i],dp[i][1]-a[i]);
    dp[i+1][1]=max(dp[i][0]-a[i],dp[i][1]+a[i]);
  }
    

 cout << dp[n][0] << endl;


}
