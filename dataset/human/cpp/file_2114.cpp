#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
const int INF=1001001001;

int main() {
  int N;
  cin>>N;
  vector<int>a(N),b(N);
  int64_t sum=0,M=0;
  for(int i=0;i<N;i++){
    cin>>a[i];
    b[i]=abs(a[i]);
    sum+=abs(a[i]);
    if(a[i]<0){M++;}
  }
  if(M%2==0){cout<<sum<<endl;}
  else{cout<<sum-2*(*min_element(b.begin(),b.end()))<<endl;}
  return 0;
}
