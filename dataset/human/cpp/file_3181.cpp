#include<iostream>
using namespace std;
int main(){
  int N, flag=0, cnt=0; cin >> N;
  long long A[N];
  for(int i=0; i<N; i++){
    cin >> A[i];
    if(A[i] == 0){
      flag = 1;
    }
    if(A[i] < 0) cnt += 1;
  }
  
  if(cnt%2 == 0) flag = 1;

  long long  min = labs(A[0]);
  for(int i=1; i<N; i++) if(labs(A[i]) < min) min = labs(A[i]);
  long long ans=0;
  for(int i=0; i<N; i++){
    ans += labs(A[i]);
  }
  if(flag == 0) ans -= 2 * min;
  cout << ans << endl;
  
  return 0;
  
}
