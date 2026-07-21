#include<bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  int m = 1, n = 0;
  int long long sum = 0;
  
  vector<int> a(N);
  for( int i = 0; i < N; i++ ) {
    cin >> a.at(i);
    if( a.at(i) < 0 ) {
      n++;
      a.at(i) *= -1;
    }
  }
  
  for( int i = 0; i < N; i++ )
    sum += a.at(i);
  int min = *min_element(a.begin(), a.end());
  sum = sum - 2 * min * ( n % 2 );
  cout << sum << endl;
  
}
