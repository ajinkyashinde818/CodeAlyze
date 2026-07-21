#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>
#include <unordered_set>
#include <cmath>
using namespace std;
typedef long long ll;

int main( int argc, char* argv[] ){
  ll N, C;
  cin >> N >> C;
  vector<ll> x(N), v(N);
  for( ll i=0; i<N; ++i ){
    cin >> x[i] >> v[i];
  }

  ll a=0, b=0, y=0, z=0;
  vector<ll> A(N,0), B(N,0), Z(N,0), Y(N,0);  
  for( ll i=0, cal=0, pos=0; i<N; ++i ){
    cal += v[i] - (x[i] - pos);
    a = max( a, cal );
    A[i] = a;
    if( x[i] < C/2 ){
      z = max(z,cal-x[i]);
      Z[i+1] = z;
    }
    pos = x[i];
  }
  for( ll i=0, cal=0, pos=C; i<N; ++i ){
    cal += v[N-1-i] - (pos-x[N-1-i]);
    b = max( b, cal );
    B[i] = b;
    if( x[N-1-i] > C/2 ){
      y = max(y,cal-(C-x[N-1-i]));
      Y[i+1] = y;
    }
    pos = x[N-1-i];
  }
  // for( auto s : A ){ cerr << s << ","; } cerr << endl;
  // for( auto s : B ){ cerr << s << ","; } cerr << endl;
  // for( auto s : Y ){ cerr << s << ","; } cerr << endl;
  // for( auto s : Z ){ cerr << s << ","; } cerr << endl;

  ll c=0;
  for( int i=0; i<N; ++i ){
    c = max( c, A[N-1-i]+Y[i] );
    c = max( c, B[N-1-i]+Z[i] );
  }
  cout << c << endl;
  return 0;
}
