#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<long long> a(N),sum(N+1,0);
  for(int i=0;i<N;i++){
    cin>>a.at(i);
    sum.at(i+1)+=a.at(i)+sum.at(i);
  }
  long long ans=sum.at(N)-2*sum.at(1);
  if(ans<0){
    ans=-ans;
  }
  for(int i=1;i<N;i++){
    long long x=sum.at(N)-2*sum.at(i);
    if(x<0){
      x=-x;
    }
    ans=min(ans,x);
  }
  cout<<ans<<endl;
}
