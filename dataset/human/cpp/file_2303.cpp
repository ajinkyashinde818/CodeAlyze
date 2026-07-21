#include<bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
  if(a % b == 0){
    return b;
  }else
  {
    return(gcd(b,a % b));
  }
}
int main(){
  int N;
  int count = 0;
  cin >> N;
  long long int sum = 0;
  vector<long long int> A(N);
  for(int i = 0; i < N; i++){
    cin >> A[i];
    if(A[i] < 0) count++;
    sum += abs(A[i]);
  }

  if(count % 2 == 0){ cout << sum; return 0; }
  
  for(int i = 0; i < N; i++){
    if(A[i] < 0) A[i] *= -1;
  }

  sort(A.begin(),A.end());
  A[0] *= -1;
  sum = sum + 2 * A[0];

  cout << sum;


    return 0;
}
