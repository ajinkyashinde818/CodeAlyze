#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  long long a[n],sum=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    sum+=a[i];
  }

  long long m=abs(sum-2*a[0]);
  long long x=0,y=sum;
  for(int i=0;i<n-1;i++){
    x+=a[i];
    y-=a[i];
    m=min(m,abs(x-y));
  }
  cout<<m<<endl;
  return 0;
}
