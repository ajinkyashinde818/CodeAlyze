#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> vec(N);
  int minus = 0;
  int64_t sum = 0;
  for(int i=0; i<N; i++){
    cin >> vec.at(i);
    if(vec.at(i) < 0){
      minus++;
      vec.at(i) *= -1;
    }
    sum += vec.at(i);
  }
  
  sort(vec.begin(),vec.end());
  if(minus %2 != 0){
    sum -= vec.at(0)*2;
  }
  cout << sum << endl;
}
