#include <iostream>
#include <algorithm>

int N;
long long a[200005];
int main(){
  std::cin>>N;
  long long sum = 0;
  for(int i=0;i<N;++i){
    std::cin>>a[i];
    sum+=a[i];
  }
  
  long long ans=200000000000005;
  long long now=0;
  for(int i=0;i<N-1;++i){
    now+=a[i];
    ans=std::min(ans,std::abs(sum-2*now));
  }
  std::cout<<ans<<std::endl;
  return 0;
}
