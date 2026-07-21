#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
  int N; cin >> N;
  vector<long long> A(N);
  int sgn = 0;
  for(int i=0; i < N; ++i){
    cin >> A[i];
    if(A[i] < 0){
      sgn += 1;
    }
  }
  vector<long long> ABS(N);
  for(int i=0; i < N; ++i){
    ABS[i] = abs(A[i]);
  }
  long long ans = 0;
  for(int i=0; i < N; ++i){
    ans += ABS[i];
  }
  if(sgn%2 != 0){
    long minim = *min_element(ABS.begin(), ABS.end());
    ans -= 2 * minim;
  }
  cout << ans << endl;
}
