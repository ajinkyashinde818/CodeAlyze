#include <bits/stdc++.h>
using namespace std;

int main() {
int64_t n;
cin>>n;
  int count=0;
vector<int64_t> a(n);
  vector<int64_t> A(n);
for(int i=0;i<n;i++){
cin>>a.at(i);
  A.at(i)=abs(a.at(i));
  if(a.at(i)<0){
    count++;
  }
}
  sort(A.begin(),A.end());
  int64_t sum=0;
  for(int i=0;i<n;i++){
    sum+=A.at(i);
  }
  if(count%2==0){
    cout<<sum;
  }
  else{
    cout<<sum-2*A.at(0);
  }
}
