#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main () {
  int N;
  cin >> N;
  int A[N];
  int absA[N];
  long long absum = 0;
  int count_neg = 0;
  
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (A[i] < 0) {
      count_neg++;
      absA[i] = -A[i];
    }
    else absA[i] = A[i];
    absum += absA[i];
  }


  if (count_neg %2 == 0) cout << absum;
  else {
    sort(absA, absA+N);
    absum -= 2*absA[0];
    cout << absum;
  }
  
}
