#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<long long> A(N),B(N);
  for(int i=0;i<N;i++){cin >> A[i]; B[i]=abs(A[i]);}
  long long ans=0;
  int cnt=0;
  for(int i=0;i<N;i++){ans+=B[i];}
  for(int i=0;i<N;i++){
    //if(A[i]==0){cout << ans << endl; return 0;}
    if(A[i]<0){cnt++;}
  }
  sort(B.begin(),B.end());
  if(cnt%2==1){cout << ans-2*B[0] << endl;}
  else{cout << ans << endl; return 0;}
}
