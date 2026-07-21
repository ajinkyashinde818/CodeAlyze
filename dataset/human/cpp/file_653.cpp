#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void fastIO(){
  ios_base::sync_with_stdio(0); cin.tie(0);
}


int main(){
  fastIO();
  int r,g,b,n;
  cin>>r>>g>>b>>n;
  vector<int>dp(3030);
  vector<int>change(3);
  change[0]=r,change[1]=g,change[2]=b;
  dp[0]=1;
  for(int i=0;i<3;i++){
  	for(int j=change[i];j<=n;j++){
  		dp[j]+=dp[j-change[i]];
  	}
  }
  cout<<dp[n]<<endl;
}
