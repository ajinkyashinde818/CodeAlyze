#include <bits/stdc++.h>
using namespace std;

int main () {
  int N;
  cin >> N;
  vector<long long>A(N);
  long long sum = 0;
  int count = 0;
  
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    if (A.at(i) < 0){
      count++;
    }
    A.at(i) = abs(A.at(i));
  }
  
  if (count % 2 == 0){
    for (int i = 0; i < N; i++) {
      sum += A.at(i);
    }
  }
  
  else {
    sort(A.begin(), A.end());
    for (int i = 0; i < N; i++) {
      sum += A.at(i);
    }
    sum -= A.at(0)*2;
  }
  
  cout << sum << endl;
}
