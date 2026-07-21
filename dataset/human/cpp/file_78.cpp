#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

typedef long long ll;

/*
  let's try computer shogi!!!
 */


int main(){
  int r,g,b,n;
  cin >> r>>g>>b>>n;
  ll dp[3001];
  ll dp_copy[3001];
  for(int i=0;i<n+1;++i){
    dp[i] = 0;
  }
  
  for(int i=0;i<n/r+1;++i){
    dp[i*r] = 1;
  }

  for(int i=0;i<n+1;++i){
    cerr<<dp[i]<<",";
    dp_copy[i] = dp[i];
    dp[i] = 0;
  }
  cerr<<endl;
  for(int i=0;i<n/g+1;++i){
    for(int j=0;j<3001;++j){
      if(j+i*g>3000){
	continue;
      }
      dp[j+i*g] += dp_copy[j];
    } 
  }
  for(int i=0;i<n+1;++i){
    cerr<<dp[i]<<",";
    dp_copy[i] = dp[i];
    dp[i] = 0;
  }
  cerr<<endl;
  
  
  for(int i=0;i<n/b+1;++i){
    for(int j=0;j<3001;++j){
      if(j+i*b>3000){
	continue;
      }
      dp[j+i*b] += dp_copy[j];
    } 
  }

  for(int i=0;i<n+1;++i){
    cerr<<dp[i]<<",";
    dp_copy[i] = dp[i];
  }
  cerr<<endl;

  cout<<dp[n]<<endl;
  return 0;
}
