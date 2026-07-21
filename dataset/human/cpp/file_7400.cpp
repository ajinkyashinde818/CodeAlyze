#include <iostream>
using namespace std;
int main(){
  int n;cin>>n;
  long long a[n];
  for(int i = 0; n > i; i++){
    cin>>a[i];
  }
  if(n==2){
    cout << abs(a[1]-a[0]) << endl;
    return 0;
  }
  long long b[n];
  b[0]=0;
  for(int i = 1; n-1 > i; i++){
    b[i]=a[i]+b[i-1];
  }
  long long ans = abs((a[n-1]+b[n-2]-b[1])-(a[0]+b[1]));
  for(int i = 1; n-1 > i; i++){
    ans = min(ans,abs((a[n-1]+b[n-2]-b[i])-(a[0]+b[i])));
  }
  cout << ans << endl;
}
