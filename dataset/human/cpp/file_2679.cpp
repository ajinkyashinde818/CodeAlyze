#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  long long sum=0;
  for (int i=0;i<N;i++){
    cin >> A[i];
  }
  sort(A.begin(),A.end());
  vector<long long> B(N+1);
  B[0]=0;
  for (int i=0;i<N;i++){
    B[i+1]=B[i]+A[i];
  }
  long long ans=0;
  for (int i=0;i<N+1;i+=2){
    ans=max(ans,B[N]-2*B[i]);
  }
  cout << ans << endl;
}
