#include <iostream>
#include <vector>

using namespace std;
using llong = long long;
llong A[200000];
llong prefix_sum[200001]={0};
int main(){
  int N;
  cin >> N;
  for(int i=0;i<N;++i){
    cin >> A[i];
    prefix_sum[i+1] += prefix_sum[i]+A[i];
  }
  
  llong min_dif = 10000000000;
  for(int i=1;i<N;++i){
    auto dif = abs(prefix_sum[N]-2*prefix_sum[i]);
    if(dif<min_dif){
      min_dif = dif;
    }
  }
  
  cout << min_dif << endl;
  return 0;
}
