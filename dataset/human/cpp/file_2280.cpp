#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int64_t N;
  cin >> N;
  int64_t a = 0;
  int64_t b = 0;
  vector<int64_t> vec(N);
for (int i = 0; i < N; i++) {
  cin >> vec.at(i);
  if(vec.at(i) < 0){
    a++;
  vec.at(i) *= -1;}
  b += vec.at(i);
}
  
  sort(vec.begin(),vec.end());
  
  if(a % 2 == 0){
    cout << b << endl;}
  else{cout << b - vec.at(0)*2 << endl;}
}
