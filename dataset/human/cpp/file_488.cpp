#include <iostream>
#include <vector>
using namespace std;

int main(void){
  int g,b,r,n,temp;
  cin >> g >> b >> r >> n;
  int ans = 0;
  for(int i = 0; i != (n / g) + 1; i++){
    for(int j = 0; j != (n / b) + 1; j++){
      temp = n - (i * g) - (j * b);
      if(temp >= 0 && temp % r == 0){
        //cout << i << j << temp << endl;
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
