#include<iostream>

using namespace std;

const int MAX_N=1e5+5;

long long a[MAX_N];
long long dp[2][MAX_N];

int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  dp[0][1]=a[0]+a[1];
  dp[1][1]=-a[0]-a[1];
  for(int j=2;j<n;j++){
    dp[0][j]=max(dp[0][j-1]+a[j],dp[1][j-1]+a[j]);
    dp[1][j]=max(dp[0][j-1]-a[j]-2*a[j-1],dp[1][j-1]-a[j]+2*a[j-1]);
  }
  cout<<max(dp[0][n-1],dp[1][n-1])<<endl;

}
