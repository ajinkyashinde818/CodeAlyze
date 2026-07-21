#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int64_t> a(N);
  int64_t sum=0;
  for(int i=0;i<N;++i){
    cin>>a.at(i);
    sum += a.at(i);
  }

  int64_t sub_sum=0;
  int64_t ans=pow(10,15);
  for(int i=0;i<N-1;++i){
    sub_sum += a.at(i);
    ans=min(ans,abs(2*sub_sum-sum));
  }

  cout<<ans<<endl;


}
