#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  long long int n;
  cin >> n;
  long long int a[n+10];
  for (int i =0;i<n;i++) cin >> a[i];
  long long int ans=0,nummi=0,mina;
  if (a[0]<0){
    mina = -a[0];
  }else{
    mina = a[0];
  }
  for (int i =0;i<n;i++){
    if (a[i] < 0){
      mina = min(mina,-a[i]);
      ans = ans - a[i];
      nummi += 1;
    }else{
      mina = min(a[i],mina);
      ans += a[i];
    }
  }
  
  if ((nummi % 2) == 0){
    cout << ans;
  }else{
    cout << ans-2*mina;
  }
}
