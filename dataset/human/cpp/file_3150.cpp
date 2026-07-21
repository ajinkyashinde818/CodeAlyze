#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  vector<long long> A;

  cin >> N;
  int count = 0;
  for(int i=0;i<N;i++){
    int buf;
    cin >> buf;
    if(buf<0){
      count++;
      A.push_back(-buf);
    }else{
      A.push_back(buf);
    }
  }

  if(count%2==0){
    long long sum = 0;
    for(int i=0;i<N;i++){
      sum += A[i];
    }
    cout << sum << endl;
  }else{
    long long min=1000000000;
    for(int i=0;i<N;i++){
      if(min>A[i]){
        min = A[i];
      }
    }
    long long sum = 0;
    for(int i=0;i<N;i++){
      sum += A[i];
    }
    cout << ( sum - 2*min ) << endl;
  }
  return 0;
}
