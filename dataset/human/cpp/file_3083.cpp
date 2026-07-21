#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  vector<int64_t> A(100010);

  cin >> N;
  int neg = 0;
  for(int i=0; i<N; i++){
    int a; cin >> a; A[i] = abs(a);
    if (a < 0) neg++;
  }

  sort(A.begin(), A.begin()+N);

  if(neg % 2 == 0){
    for(int i=0; i<N; i++){
      if(A[i] < 0) A[i] *= -1;
    } 
  } else {
    A[0] = min(A[0], -1 * A[0]); 
    for(int i=1; i<N; i++){
      if(A[i] < 0) A[i] *= -1;
    }
  }

  int64_t ans = 0;
  for(int i=0; i<N; i++){
    //cout << A[i] << endl;
    ans += A[i];
  }
  cout << ans << endl;
}
