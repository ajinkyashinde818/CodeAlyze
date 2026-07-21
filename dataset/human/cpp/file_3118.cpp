#include <iostream>
#include <string.h>
#include <climits>
using namespace std;




int main(){
  // INPUT
  int n;
  cin >> n;
  int a[n+2];
  long long sum = 0;
  int count = 0;
  int intmin = INT_MAX;
  int minI = 0;
  a[0] = 0; a[n+1] = 0;
  for(int i=1;i<=n;i++){
    cin >> a[i];
    if(a[i]>0){sum = sum + a[i];}
    else{
      sum = sum - a[i];
      //cout << sum << endl;
      count++;
    }
    if (intmin > abs(a[i]) ){
      minI= i;
      intmin = abs(a[i]);
    }
  }

  // CALC
  if(count%2 == 0){
    cout << sum << endl;
  }else{
    cout << sum - abs(2*intmin) << endl;
  }






  return 0;
}
