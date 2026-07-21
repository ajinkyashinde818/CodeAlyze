#include <iostream>
#include <vector>

using namespace std;

int main(void){
  int N;
  cin >> N;
  
  long long int total;
  
  vector<long long int> A(N);
  for(int i = 0; i < N; i++){
    cin >> A[i];
    total += A[i];
  }
  long long int snuke = 0LL;
  long long int arai = total;
  long long int minDiff = 9000000000;
  for(int i = 0; i < N-1; i++){
    snuke += A[i];
    arai -= A[i];
    minDiff = min(abs(snuke - arai),minDiff);
  }
  cout << minDiff;
  


}
