#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  int N;
  cin >> N;
  
  vector<int> A(N);
  int nega = 0;
  for (int i = 0; i < N; i++){
    int a;
    cin >> a;
    A.at(i) = abs(a);
    
    if (a < 0){
      nega++;
    }
  }

  sort(A.begin(), A.end());
  
  ll ans = 0;
  for (int i = 1; i < N; i++){
    ans += A.at(i);
  }
  
  if (nega % 2 == 0){
    ans += A.at(0);
  }
  else{
    ans -= A.at(0);
  }
  
  cout << ans << endl;
}
