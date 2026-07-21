#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
int main(){
  int a,b;
  cin >> a >> b;
  if(a >= 10){
    cout << b << endl;
  }
  else{
    cout << b + 100 * (10 - a) << endl;
  }
  return 0;
}
