#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  int zero=0;
  int minus=0;
  long ans=0;
  cin >> N;
  vector<long> vec(N);
  for (int i = 0; i<N; i++){
    cin >> vec.at(i);
    if ( vec.at(i) < 0){
      minus++;
      vec.at(i) = vec.at(i)*(-1);
    }
    if ( vec.at(i) == 0){
      zero ++;
    }
  }
  sort(vec.begin(), vec.end());
  if( zero > 0){
    ans = vec.at(0);
  }
  else if( minus%2 == 0){
    ans = vec.at(0);
  }
  else{
    ans = vec.at(0)*(-1);
  }
    for (int i=1; i<N; i++){
      ans = ans + vec.at(i);
    }
  cout << ans << endl;
      

}
