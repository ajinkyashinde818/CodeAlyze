#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<long long> A(N),B(N),C(N);
  for(long long &i:A)
    cin>>i;
  B[0]=0,C[N-1]=0;
  for(long long i=1;i<N;i++){
    B[i]=B[i-1]+A[i-1];
    C[N-i-1]=C[N-i]+A[N-i];
  }
  long long j=1000000000000000;
  for(long long i=1;i<N;i++)
    j=min(j,abs(B[i]-C[i-1]));
  cout<<j<<endl;
}
