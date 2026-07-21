#include<iostream>
#include<vector>
using namespace std;
int main () {
  int N;
  cin >> N;
  long int sum = 0;
  int nMinus = 0;
  //int nPlus = 0;
  int nZero = 0;
  int absMin = 2000000000;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    sum += abs(A[i]);

    if (abs(A[i]) < absMin && A[i]!=0) {
      absMin = abs(A[i]);
    }
    
    if (A[i] < 0) {
      nMinus++;
    } else if (A[i] == 0) {
      nZero++;
    }
  }

  if (nZero > 0 || nMinus%2 == 0) {
    sum = sum;
  } else {
    sum = sum - 2*absMin;
  }

  cout<<sum<<endl;
  return 0;
}
