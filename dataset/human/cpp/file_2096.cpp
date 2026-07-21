#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  long long a[n],sum = 0;
  int i,pm=1,minh=1000000001;
  for(i=0;i<n;i++){
    cin >> a[i];
    if(a[i]<0){
      pm *= -1;
      a[i] *= -1;
    }
    if(minh>a[i]) minh = a[i];
    sum += a[i];
  }
  if(pm==1) cout << sum << endl;
  else cout << (sum - minh * 2) << endl;
  return 0;
}
