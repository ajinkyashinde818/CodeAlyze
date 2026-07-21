#include <iostream>
#include <vector>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<long long> A(N);
  int flag = 0;
  long long sum = 0;
  int cnt = 0;
  long long m = 1e18;
  for(int i = 0; i < N; i++){
    cin >> A[i];
    if(A[i] == 0) flag = 1;
    sum += abs(A[i]);
    if(A[i] < 0) cnt++;
    m = min(m, abs(A[i]));
  }
  if(flag == 1 || cnt % 2 == 0){
    cout << sum << endl;
    return 0;
  }
  cout << sum - m * 2 << endl;
}
