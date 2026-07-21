#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

int main(){
  int N;
  int counter = 0;
  int counter_0 = 0;
  long long sum = 0;
  cin >> N;
  vector<long> A(N);
  for(int i = 0;i < N;i++){
    cin >> A[i];
    if(A[i] < 0)counter++;
    if(A[i] == 0)counter_0++;
  }
  if(counter % 2 == 0 || counter_0 > 0){
    for(int i = 0;i < N;i++){
      if(A[i] < 0)A[i] = -A[i];
      sum += A[i];
    }
  }else{
    for(int i = 0;i < N;i++){
      if(A[i] < 0)A[i] = -A[i];
      sum += A[i];
    }
    sort(A.begin(),A.end());
    sum -= A[0] * 2;
  }
  cout << sum << endl;
}
