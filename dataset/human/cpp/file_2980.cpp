#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;cin>>N;
  vector<int>A(N);
  
  int count=0;
  for(int i=0;i<N;i++){
    cin>>A.at(i);
    if(A.at(i)<0)
      count++;
    A.at(i)=abs(A.at(i));
  }
  
  sort(A.begin(),A.end());
  
  long long res=0;
  
  if(count%2==0){
    for(int i=0;i<N;i++)
      res+=A.at(i);
  }
  else{
    for(int i=1;i<N;i++)
      res+=A.at(i);
    res-=A.at(0);
  }
  
  cout<<res;
}
