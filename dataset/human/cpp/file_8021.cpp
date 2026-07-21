#include<bits/stdc++.h>
using namespace std;
int main(){
  long long N;
  cin>>N;
  vector<long long>A(N);
  vector<long long>sum(N);
  sum.at(0)=0;
  for(int i=0;i<N;i++){
    cin>>A.at(i);
    if(i==0){
      sum.at(i)=A.at(i);
    }
    else{
      sum.at(i)=sum.at(i-1)+A.at(i);
    }
  }
  long long ans=2000000000;
  for(int i=0;i<N-1;i++){
    ans=min(ans,abs(sum.at(i)*2-sum.at(N-1)));
  }
  cout<<ans<<endl;
}
