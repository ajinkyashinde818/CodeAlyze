#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; cin >> N;
  if(N==1){
    cout << 1 << endl;
    return 0;
  }
  string S; cin >> S;
  int k=S.size();
  sort(S.begin(),S.end());
  S+='A';
  int count=2;
  long long ans=1;
  for(int i=1;i<=k;i++){
    if(S[i]==S[i-1]){
      count++;
    }
    else{
      ans*=count;
      ans%=1000000007;
      count=2;
    }
  }
  cout << ans-1 << endl;
}
