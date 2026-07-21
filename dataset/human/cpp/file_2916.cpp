#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cmath>

int main(){
  long int N;
  std::cin>>N;
  std::vector<int> v(N);
  std::copy_n(std::istream_iterator<int>(std::cin),N,v.begin());
  long int S = 0;
  long int min_ab = std::fabs(v[0]);
  long int minuscount=0;
  for(long int i = 0 ; i < N ; i++ ){
    S += std::fabs(v[i]);
    if(min_ab >= std::fabs(v[i])){
      min_ab = std::fabs(v[i]);
    }
    if(v[i]<0) minuscount++;
  }
  if(minuscount % 2 == 0){
    std::cout<<S<<std::endl;
  }else{
    std::cout<<S-2*min_ab<<std::endl;
  }
  return 0;
}
