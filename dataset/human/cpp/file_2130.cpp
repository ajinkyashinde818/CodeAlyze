#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
  long long n;
  std::vector<signed long long> A;

  cin >> n;
  A.resize(n);
  for (long long i=0;i<n;++i) {
    cin >> A[i];
  }
  sort(A.begin(), A.end(), [](auto a, auto b) {
    return abs(b) < abs(a);
  });
  
  for (unsigned long long i=0;i<n-1;++i) {
    if (A[i]<0) {
      A[i] = -A[i];
      A[i+1] = -A[i+1];
    }
  }
  /*
  for (int i=0;i<n;++i) {
    cout << A[i] << " ";
  }
  cout << endl;
  */

  unsigned long long MAX = 0;
  for (int i=0;i<n;++i) {
    MAX += A[i];
  }
  cout << MAX << endl;

  return 0;
}
