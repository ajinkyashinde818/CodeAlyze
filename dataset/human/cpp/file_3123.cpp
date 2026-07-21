#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;



int main() {

  int N;
  cin >> N;
  
  long A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  
  long minVal = LONG_MAX;
  int minusCount = 0;
  long sum = 0;
  for (int i = 0; i < N; i++) {
    sum += abs(A[i]);
    minVal = min(minVal,abs(A[i]));
    if(A[i]<0) minusCount++;
  }
  if(minusCount%2==1) sum -= (minVal*2);

  cout << sum << endl;

  return 0;
}
