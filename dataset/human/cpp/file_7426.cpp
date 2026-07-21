#include <bits/stdc++.h>
using namespace std;

int main(){
  
int N;
  cin >> N;
long long sum = 0, tum = 0;
long long mi = 200000000000010;  
long long A[N];
  
  for(int i = 0;i < N;i++){
  cin >> A[i];
  sum += A[i];  
  }
  
  for(int i = 0;i < N;i++){
  tum += A[i];  
  if(i+ 1 < N) mi = min(mi, abs(sum - 2 * tum));  
  }
  
  cout << mi << endl;
  return 0;
  
}
