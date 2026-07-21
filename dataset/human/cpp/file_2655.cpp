#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

long getGCD(long x, long y){
  if (y == 0) {
    return x;     
  }
  return getGCD(y, x % y);
}

int main(int argc, char const *argv[])
{
  int N;
  bool NegCount = 0;
  long tmp = 0, min = 10000000000;
  unsigned long long sum = 0;
  cin >> N;
  vector<long> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
    if(A[i] < 0){
      NegCount = !NegCount;
    }
    if(labs(A[i]) < min){
      min = labs(A[i]);
    }
  }
  for(int i=0;i < N;i++){
    sum += labs(A[i]);
  }
  if(NegCount != 0){
    sum = sum - min * 2;
  }
  // cout << NegCount << endl;
  // cout << min << endl;
  cout << sum << endl;
  return 0;
}
