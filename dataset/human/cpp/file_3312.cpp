#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  int m=1000000000;
  int c=0;
  for(int i=0;i<n;i++){
    cin>>a.at(i);
    m=min(m,abs(a.at(i)));
    c+=(a.at(i)<=0?1:0);
  }
  int64_t s=0;
  for(int i=0;i<n;i++)
    s+=abs(a.at(i));
  cout<<s-(c%2==1?m*2:0)<<endl;
}
