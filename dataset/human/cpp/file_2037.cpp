#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int gcd(int a,int b){
  if(b==0)return 0;
  return gcd(b,b%a);
}

int main(){
  long int n,c = 0,b = 0,min;
  cin >> n;

  for(int i = 0; i < n; ++i){
    long int a;
    cin >> a;
    if(i == 0)
      min = abs(a);
    if(a < 0)
      c++;
    b += abs(a);
    if(abs(a) < abs(min)){
      min = abs(a);
    }
  }

  cout << (c % 2 == 0 ? b : b - min*2) << endl;
}
