#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m=0;
  cin >> n;
  vector<int64_t>a(n);
  for(int i=0;i<n;i++){
    cin >> a.at(i);
    if(a.at(i)<0)m++;  
    a.at(i)=abs(a.at(i));
  }
  int64_t ans=0;
  for(int i=0;i<n;i++) ans+=a.at(i);
  if(m%2==1){
    int64_t s=1000000000;
    for(int i=0;i<n;i++)s=min(s,a.at(i));
    ans-=s*2;
  }
  cout << ans << endl;
  return 0;
}
