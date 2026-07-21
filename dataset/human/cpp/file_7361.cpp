#include<iostream>
#include<vector>

using namespace std;

long long abs(long long a, long long b){
  if( a >= b){return a - b;}
  else{return b - a;}}

int main(){
  int N; cin >> N;
  vector<long long> a(N);  long long c = 0;
  for(int i = 0; i < N; i++){ cin >> a[i]; c += a[i];}
  
  long long x = 0; long long min_diff = 1e18;
  for(int i = 0; i < N; i++){
    x += a[i];
     if(i < N - 1){min_diff = min( min_diff,abs( c ,2*x));}}
  
  cout << min_diff ; return 0;
}
