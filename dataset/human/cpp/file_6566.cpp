#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; cin >> N;
  vector<char> A(2*N);
  for(int i=0;i<2*N;i++){
    cin >> A[i];
  }
  if(A[0]=='W' || A[2*N-1]=='W'){
    cout << 0 << endl;
    return 0;
  }
  vector<int> B(2*N);
  B[0]=1;
  for(int i=1;i<2*N;i++){
    if(A[i-1]==A[i]){
      B[i]=B[i-1]*(-1);
    }
    else B[i]=B[i-1];
  }
  long long count=1;
  long long ans=1;
  for(int i=1;i<2*N;i++){
    if(B[i]==1){
      count++;
    }
    else {
      ans=(ans*count)%1000000007;
      count--;
    }
  }
  if(count!=0){
    cout << 0 << endl;
    return 0;
  }
  for(int i=1;i<=N;i++){
    ans=(ans*i)%1000000007;
  }
  cout << ans << endl;
}
