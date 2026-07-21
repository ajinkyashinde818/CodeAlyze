#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int main(void){
  int N;
  int count = 0;
  long int min = LONG_MAX;
  long int sum=0;
  cin >> N;
  vector<long int> data(N);
  for (int i=0;i<N;i++){
    cin >> data[i];
    if (data[i]<0) count++;
    if (abs(data[i]) < min) min = abs(data[i]);
    sum += abs(data[i]);
  }
  if (! (count%2)) cout << sum << endl;
  else cout << sum-2*min << endl;
  return 0;
}
