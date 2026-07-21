#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  vector<int64_t>A(N);
  for(int i=0;i<N;i++)
    cin>>A.at(i);
  int64_t sum=0;
  for(int i=0;i<N;i++)
    sum+=A.at(i);
  vector<int64_t>B(N-1);
  int64_t x=0;
  for(int i=0;i<N-1;i++){
  x+=A.at(i);
  B.at(i)=abs(sum-2*x);
  }sort(B.begin(),B.end());
  cout<<B.at(0)<<endl;
   return 0;
}
