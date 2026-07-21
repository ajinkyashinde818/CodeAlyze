#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int N;
int A[123456];
int main(){
  LL sum=0;
  cin>>N;for(int i=0;i<N;++i){cin>>A[i];sum+=A[i];}
  sort(A,A+N);
  LL ans=sum;
  for(int i=0;i<N;i+=2){
    if(i+1<N){
      A[i]=-A[i];
      A[i+1]=-A[i+1];
      sum+=A[i]*2;
      sum+=A[i+1]*2;
      ans=max(sum,ans);
    }
  }
  cout<<ans<<endl;
  return 0;
}
