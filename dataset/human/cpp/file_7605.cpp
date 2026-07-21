#include <iostream>
#include <cstdlib>
using namespace std;
int main(){

  long long a[200000],tmp;
  int n,i;

  cin>>n;
  cin>>a[0];
  for(i=1;i<n;i++){
    cin>>tmp;
    a[i]=a[i-1]+tmp;
  }
  long long result=114514191911451419;
  for(i=0;i<n-1;i++) result=min(result,abs((a[n-1]-a[i])-a[i]));
  cout<<result<<endl;
  return 0;
}
