#include<bits/stdc++.h>
using namespace std;

int main(){
  int N; cin>>N;
  long long S=0;
  vector<long long>part_S(N-1);
  for(int i=0;i<N;i++){
    int a; cin>>a;
    S+=a;
    if(i==0)
      part_S.at(i)=a;
    else if(i!=N-1)
      part_S.at(i)=part_S.at(i-1)+a;
  }
  
  long long res=1000000000000;
  
  for(int i=0;i<N-1;i++){
    res=min(res,abs(S-2*part_S.at(i)));
  }
  
  cout<<res<<endl;
}
