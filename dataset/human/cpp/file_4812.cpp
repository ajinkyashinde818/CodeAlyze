#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
using namespace std;

int main(){
  int a, b;
  int ret = 0;
  /*処理系*/
  cin >> a >> b;
  if(a < 10){
    ret = 100 * (10 - a);
    ret += b;
  }
  else{
    ret = b;
  }
  cout << ret;
  return 0;
}
