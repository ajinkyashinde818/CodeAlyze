#include<bits/stdc++.h>
using namespace std;
static const int64_t mod=1000000007;
int main(){
  int64_t N;cin>>N;
  string s;cin>>s;
  vector<int64_t>A(2*N);
  for(int i=0;i<2*N;i++){
  if((i%2==0 &&s.at(i)=='B')||(i%2==1 && s.at(i)=='W'))
    A.at(i)=0;
    else
      A.at(i)=1;
  }int64_t sum=0;
  for(int i=0;i<2*N;i++)
    sum+=A.at(i);
  if(sum!=N)
    cout<<0<<endl;
  else{
  int64_t ans=1;int64_t a=0;
    for(int i=2*N-1;0<=i;i--){
    if(A.at(i)==1)a++;
      if(A.at(i)==0){ans=(ans*a)%mod;a--;}
      
    }for(int64_t i=1;i<=N;i++)
      ans=(i*ans)%mod;
    cout<<ans<<endl;
   }
  return 0;
}
