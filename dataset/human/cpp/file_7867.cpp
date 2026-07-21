//A.cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long min(long long A, long long B);

int main(){
  int N,A;
  cin >> N;
  long long S[N];
  cin >> A;
  S[0] = A;
  for(int i = 0; i < N-1; i++){
    cin >> A;
    S[i+1] = S[i] + A;
  }

  long long Amin;
  Amin = abs(S[N-1]-S[0]-S[0]);
  for(int i = 1; i < N-1; i++){
    Amin = min(Amin,abs(S[N-1]-S[i]-S[i]));

  }

  printf("%lld\n",Amin);
  return 0;
}

long long min(long long A, long long B){
  if(A<=B) return A;
  else return B;
}
