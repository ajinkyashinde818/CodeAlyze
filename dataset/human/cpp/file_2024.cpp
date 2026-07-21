#include  <bits/stdc++.h>
using namespace std;
//  pair<int,int>pa;
//  vector<pair<int,int>>vec;

int main(){
 int N,M=0;
  long long ans=0;
  cin>>N;
  vector<int>g(N);
  vector<int>v(N);
  for(int i=0;i<N;i++){
    cin >>g.at(i);
    v.at(i)=abs(g.at(i));
  }
  
  sort(g.begin(),g.end());
  
  for(int i=0;i<N;i++){
    if(g.at(i)<0){
      M=i+1;
    }
    else{break;}
  }
  if(M%2==0){
    for(int i=0;i<N;i++){
      ans+=v.at(i);
    }
  }
  
  else{
      sort(v.begin(),v.end());
    for(int i=1;i<N;i++){
      ans+=v.at(i);
    }
    ans-=v.at(0);
  }
  cout << ans<<endl; 
}
