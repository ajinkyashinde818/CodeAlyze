#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int n,sum,x,y,min;
  cin>>n;
  vector<long long int> a(n);
  sum=x=0;
  min=100000000000;
  for(long int i=0;i<n;i++){
    cin>>a[i];
    sum+=a[i];
  }
  for(long int i=0;i<n-1;i++){
    x+=a[i];
    y=abs(sum-2*x);
    if(min>y)
      min=y;
  }
  cout<<min<<endl;
}
