#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; ++i) cin >> A[i];
  long long ans = 0;
  int mi = 1e9, c = 0;
  for(int i = 0; i < N; ++i){
    if(A[i] > 0) ans += A[i], mi = min(mi,A[i]);
    else ans -= A[i], mi = min(mi,-A[i]), ++c;
  }
  if(c%2)
    ans -= 2*mi;
  cout << ans << endl;
}
