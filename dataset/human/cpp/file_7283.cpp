#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int64_t N;
  cin>>N;
  
  vector<int64_t> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec.at(i);
  }
  int64_t sum=0;
  for(int i=0;i<N;i++){
    sum+=vec.at(i);
  }
  int64_t S=0;
  int64_t A=sum;
  int64_t D=100000000000000;
  for(int i=0;i<N-1;i++){
    S+=vec.at(i);
    A-=vec.at(i);
    D=min(D,abs(S-A));
  }
  cout<<D<<endl;
    
}
