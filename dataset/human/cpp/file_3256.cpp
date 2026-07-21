#include<bits/stdc++.h>
using namespace std;

int main(){
  long N, min = 1000000000, tot = 0, count = 0, re;
  cin >> N;
  
  vector<long> A(N), h(N);
  for (int i = 0; i < N; i++){
    cin >> A.at(i);
    int a = fabs(A.at(i));
    if(A.at(i) < 0){
      count++;
    }
    if(a < min){
      min = a;
    }
    tot += a;
  }
  
  if(count%2 == 0){
    re = tot;
  } else {
    re = tot - 2*min;
  }
  
  cout << re << endl;
  return 0;
}
