#include<iostream>
using namespace std;

int main(){
  int N;  cin >> N;
  long long sum = 0;
  long long min = 1LL << 60;
  int minuscount = 0;
  for(int i=0;i<N;i++){
    long long A;  cin >> A;
    if(A < 0){
      A *= -1;
      minuscount ++;
    }
    if(min > A) min = A;
    sum += A;
  }
  if(minuscount % 2 == 0) cout << sum << endl;
  else  cout << sum - 2*min << endl;
}
