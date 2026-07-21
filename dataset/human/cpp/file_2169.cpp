#include <iostream>
// inline long long abs(long long x) {
//   long long res = x > 0?x:-x;
//   return(res);
// }

using namespace std;

int main(){
  long long result = 0;
  long long min_a = 9223372036854775807;
  long long zeros = 0;
  long long minuses = 0;
  long long n;
  cin >> n;
  for (int i=0;i<n;i++) {
    long long a;
    cin >> a;
    if (a < 0) {
      minuses++;
      result += -a;
    } else if (a==0){
      zeros++;
    } else {
      result += a;
    }
    if (abs(a) < min_a) {
      min_a = abs(a);
    }
  }
  if (zeros > 0) {
    cout << result << endl;
  } else if (minuses % 2 == 0) {
    cout << result << endl;
  } else {
    cout << result - 2*min_a << endl;
  }
  return(0);
}
