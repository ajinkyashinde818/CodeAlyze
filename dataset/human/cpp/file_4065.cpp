#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair< int, int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< ll > vl;
typedef vector< vl > vvl;
typedef vector< pii > vp;
typedef vector< vp > vvp;
typedef vector< string > vs;
typedef vector< double > vd;
typedef vector< vd > vvd;

template< class T1, class T2 >
int upmin( T1 &x, T2 v ){
  if( x > v ){
    x = v;
    return 1;
  }
  return 0;
}

template< class T1, class T2 >
int upmax( T1 &x, T2 v ){
  if( x < v ){
    x = v;
    return 1;
  }
  return 0;
}

const int INF = 0x3f3f3f3f;

int sx, sy, gx, gy;
int N;
vi X, Y, R;

void init(){
  cin >> sx >> sy >> gx >> gy;
  cin >> N;
  X = Y = R = vi( N );
  for( int i = 0; i < N; ++i )
    cin >> X[ i ] >> Y[ i ] >> R[ i ];
}

vd dp;

double eu_dis( double x, double y, double a, double b ){
  double dx = x - a;
  double dy = y - b;
  return sqrt( dx * dx + dy * dy );
}

void preprocess(){
  dp = vd( N );
  typedef tuple< double, int > tdi;
  priority_queue< tdi, vector< tdi >, greater< tdi > > pq;
  for( int i = 0; i < N; ++i )
    dp[ i ] = max( 0.0, eu_dis( X[ i ], Y[ i ], sx, sy ) - R[ i ] ),
    pq.emplace( dp[ i ], i );
  while( not pq.empty() ){
    double d; int u; tie( d, u ) = pq.top(); pq.pop();
    if( d != dp[ u ] ) continue;
    for( int i = 0; i < N; ++i ) if( i != u )
      if( upmin( dp[ i ], dp[ u ] + max( 0.0, eu_dis( X[ i ], Y[ i ], X[ u ], Y[ u ] ) - R[ i ] - R[ u ] ) ) )
        pq.emplace( dp[ i ], i ); 
  }
}

void solve(){
  double ans = eu_dis( gx, gy, sx, sy );
  for( int i = 0; i < N; ++i )
    upmin( ans, dp[ i ] + max( 0.0, eu_dis( X[ i ], Y[ i ], gx, gy ) - R[ i ] ) );
  cout << fixed << setprecision( 12 ) << ans << endl;
}

signed main(){
  ios::sync_with_stdio( 0 );
  init();
  preprocess();
  solve();
  return 0;
}
