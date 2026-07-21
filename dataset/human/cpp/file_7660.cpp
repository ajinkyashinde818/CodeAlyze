#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  vector<int>a(n);
  vector<int64_t>s(n,0);
  cin>>a.at(0);
  s.at(0)=a.at(0);
  for(int i=1;i<n;i++){
    cin>>a.at(i);
    s.at(i)=s.at(i-1)+a.at(i);
  }
  int64_t ans=abs(s.at(0)-(s.at(n-1)-s.at(0)));
  for(int i=1;i<n-1;i++){
    ans=min(ans,abs(s.at(i)-(s.at(n-1)-s.at(i))));
  }
  cout <<ans<<endl;
}
