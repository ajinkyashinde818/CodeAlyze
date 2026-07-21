#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
  int N; cin >> N;
  vector <long> A(N);
  for (int i = 0; i < N; i++){
    cin >> A.at(i);
  }
  int cnt = 0;
  for (int i = 0; i < N; i++){
    if (A.at(i) < 0){
      A.at(i) = - A.at(i);
      cnt++;
    }
  }
  long sum = 0;
  for (int i = 0; i < N; i++){
    sum += A.at(i);
  }
  if(cnt % 2 == 0) cout << sum << endl;

  else{
    long m = (long)*min_element(A.begin(),A.end());
    cout << sum - 2*m << endl;
  }
}
