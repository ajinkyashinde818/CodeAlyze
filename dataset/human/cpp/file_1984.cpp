#include <bits/stdc++.h>
using namespace std;

int main(){
  long int A;
  int N;
  long int x;//xはマイナスの数
  long int min = 1000000000;
  long int sum = 0;
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> A;
    if(A < 0){
      A = -A;
      x++;
    }
    if(min > A){
      min = A;
    }
    sum += A;
  }
  if(x%2 == 1){
    sum -= 2*min;
  }
  cout << sum << endl;
}
