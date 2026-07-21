#include <bits/stdc++.h>
using namespace std;
int main(){
  long long int n;
  cin >>n;
  long long int a[n],p=0,l=0,m=0,sum=0,mi=LLONG_MAX;
  for(int i=0;i<n;i++){
    cin >>a[i];
    mi=min(mi,abs(a[i]));
    sum+=abs(a[i]);
    if(a[i]>0)p++;
    else if(a[i]<0)m++;
    else l++;
  }
  if (l>0 || m%2==0)cout << sum <<endl;
  else cout << sum-2*mi<<endl;
}
