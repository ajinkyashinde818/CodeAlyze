#include<iostream>
#include<math.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  long long min;
  long long sun=0, arai=0;
  cin >> n;
  long long* num = new long long[n];

  for (int i = 0; i < n; i++) {
    cin >>num[i];
  }
  for (int i = 0; i < n; i++) {
    arai += num[i];
  }
  sun += num[0];
  arai -= num[0];
  min = abs(sun-arai);

  for (int i = 1; i < n-1; i++) {
    sun += num[i];
    arai -= num[i];
    if(abs(sun-arai)<min){
      min = abs(sun-arai);
    }
  }
  cout << min <<endl;
  return 0;
}
