#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
int main(){
  int N;
  cin >> N;
  
  int A[N];
  int min = 10000000000;
  long long int sum=0;
  bool sign = true;
  
  for(int i = 0; i < N; i++){
    cin >> A[i];
    if(A[i] < 0){
      sign = !sign;
      A[i] *= -1;
    }
    sum += A[i];
    if( A[i] < min){
      min = A[i];
    }
  }
  if(!sign){
    sum -= 2 * min;
  }
  cout << sum << endl;
  
  return 0; 
}
