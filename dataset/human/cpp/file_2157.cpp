#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;
  vector<long long>A(N);
  long long shou=10000000000000;
  int c=0;
  long long count=0;
  for(int i=0;i<N;i++){
    cin>>A[i];
    if(A[i]<0)c++;
    count+=abs(A[i]);
    shou=min(shou,abs(A[i]));
  }
  if(c%2==0)cout<<count<<"\n";
  else cout<<count-shou*2<<"\n";
}
