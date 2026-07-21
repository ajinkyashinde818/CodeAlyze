#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<long long> a(N); 
  for(int i=0; i<N; i++) cin >> a.at(i);
  vector<long long> div(N);
  div.at(0)=a.at(0);
  for(int i=1; i<N; i++){
    div.at(i)=div.at(i-1)+a.at(i);
  }
  long long ans=100000000000001;
  for(int i=0; i<N-1; i++){
    ans = min(ans, abs(div.at(N-1)-div.at(i)-div.at(i)));
  }
  cout << ans << endl;
}
