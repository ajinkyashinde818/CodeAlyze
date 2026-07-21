#include <iostream>

using namespace std;

int main(){
  int N,A[100010],abs_min=1000000010,cnt=0;
  long long sum=0;
  cin >> N;
  for(int i=0;i<N;i++) cin >> A[i];

  for(int i=0;i<N;i++){
    abs_min=min(abs_min,abs(A[i]));
    if(A[i]<0) cnt++;
  }

  for(int i=0;i<N;i++) sum+=abs(A[i]);
  if(cnt%2==0) cout << sum << endl;
  else cout << sum-abs_min*2 << endl;
  return 0;
}
