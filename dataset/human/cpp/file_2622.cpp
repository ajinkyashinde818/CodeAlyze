#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  vector<int64_t>A(N);
  for(int i=0;i<N;i++)
    cin>>A.at(i);
  sort(A.begin(),A.end());
  int64_t ans=0;
  for(int i=0;i<N;i++)
    ans+=abs(A.at(i));
  auto itr=upper_bound(A.begin(),A.end(),0);
  int k=distance(A.begin(),itr);
  if(k%2==0)
    cout<<ans<<endl;
  else if(k==N){
  ans+=2*A.at(N-1);
    cout<<ans<<endl;
  }
  else{
    int64_t Min=2*min(abs(A.at(k-1)),A.at(k));
    ans-=Min;
    cout<<ans<<endl;
  
  }
   return 0;
}
