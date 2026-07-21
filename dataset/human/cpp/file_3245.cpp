#include <iostream>
#include <cmath>
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  long tmp;
  long long min = 1000000000;
  long long sum = 0;
  int nmin = 0;
  for(int i = 0; i<n; i++){
    cin >> tmp;
    if(tmp < 0) nmin++;
    tmp = abs(tmp);
    sum += tmp;
    if(min > tmp) min = tmp;
  }
  if(nmin%2==1) sum -= min * 2;
  cout << sum << "\n";
  return 0;
}
