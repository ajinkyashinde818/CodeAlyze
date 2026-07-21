#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int c[3],N;
  cin>>c[0]>>c[1]>>c[2]>>N;
  int ans=0;
  for(int i=0;i<=(N/c[0])+1;i++){
    for(int j=0;j<=(N/c[1])+1;j++){
      if(c[0]*i+c[1]*j<=N&&(N-c[0]*i-c[1]*j)%c[2]==0) ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}
