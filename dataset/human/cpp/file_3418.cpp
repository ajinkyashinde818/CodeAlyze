#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int64_t> A(N);
  int64_t sum=0;
  int sign=0;
  int64_t absMin=1e9+1;
  for(int i=0;i<N;i++){
    cin>>A[i];
    sum += abs(A[i]);
    if(A[i]<0) sign++;
    absMin = min(absMin,abs(A[i]));
  }
  if(sign%2==0){
    cout<<sum<<endl;
  }else{
    cout<<sum-2*absMin<<endl;
  }
  return 0;
}
