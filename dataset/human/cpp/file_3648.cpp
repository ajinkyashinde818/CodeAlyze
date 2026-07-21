#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  long long N,cnt=0,ans=0; cin>>N;
  vector<long long> A(N,0); 
  for(long long i=0;i<N;i++){
    long long temp; cin>>temp;
    if(temp<0) cnt++;
    A[i]=abs(temp);
  }

  sort(A.begin(),A.end());
  reverse(A.begin(),A.end());
  for(long long i=0;i<N-1;i++) ans+=A[i];
  if(cnt%2==0)ans+=A[N-1];
  else ans-=A[N-1];

  cout<<ans<<endl;

  return 0;
}
