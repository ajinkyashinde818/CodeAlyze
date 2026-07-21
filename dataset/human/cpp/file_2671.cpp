#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >>n;
  vector<int>a(n);
  int count=0;
  long long sum=0;
  int shou=INT_MAX;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    shou=min(shou,abs(x));
    sum+=abs(x);
    if(x<0)count++;
  }
  if(count%2==0){
    cout<<sum<<endl;
  }else{
    sum-=shou*2;
    cout<<sum<<endl;
  }
  return 0;
}
