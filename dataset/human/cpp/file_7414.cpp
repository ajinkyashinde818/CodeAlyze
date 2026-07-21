#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int N,res,sum=0,sumx=0;
  cin>>N;
  vector<long long int> as(N);
  for(int i=0;i<N;i++){cin>>as.at(i);sum+=as.at(i);}
  sumx+=as.at(0);
  res=abs(sum-2*sumx);
  for(int i=1;i<N-1;i++){
    sumx+=as.at(i);
    res=min(res,abs(sum-2*sumx));
  }
  cout<<res<<endl;
}
