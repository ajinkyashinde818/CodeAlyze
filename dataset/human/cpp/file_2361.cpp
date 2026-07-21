#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int N;
  cin >> N;
  long long A[N];
  int p = 1; // parity
  bool flag = false;

  for(int i = 0; i < N; i++){
    cin >> A[i];
    if(A[i] < 0){
      p *= -1;
    }
    else if(A[i] == 0){
      flag = true;
    }
  }
  /******
  for(int i = 0; i < N; i++){
    cout << A[i] << "\n";
  }  
  ******/

  if(p == 1) flag = true;
  for(int i = 0; i < N; i++){
    A[i] = abs(A[i]);
  }  
  unsigned long ans = 0;
  for(int i = 0; i < N; i++){
    ans += A[i];
  }
    
  if(flag == false){
    sort(A, &A[N]);
    ans -= A[0]*2;
  }

  cout << ans << "\n";

  return 0;
}
