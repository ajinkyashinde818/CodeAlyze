#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <numeric>
#include <iterator>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef istringstream ISS;
typedef ostringstream OSS;

#define REP( i, m, n ) for ( int i = (int)( m ); i < (int)( n ); ++i )
#define FOR( v, c ) for ( auto &v : c )
#define EACH( it, c ) for ( auto it = c.begin(); it != c.end(); ++it )
#define ALL( c ) (c).begin(), (c).end()
#define DRANGE( c, p ) (c).begin(), (c).begin() + p, (c).end()

#define PB( n ) push_back( n )
#define MP( a, b ) make_pair( ( a ), ( b ) )
#define EXIST( c, e ) ( (c).find( e ) != (c).end() )

#define fst first
#define snd second

#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define DEBUG( x ) cerr << __FILE__ << ":" << __LINE__ << ": " << #x << " = " << ( x ) << endl

#include <complex>
typedef complex<double> Point;
const double EPS = 1e-8;

// テ・ツ?・テ・ツ環崚」ツつケテ」ツδ暗」ツδェテ」ツδシテ」ツδ?」ツ?凝」ツつ嘉・ツョツ淌ヲツ閉ーテ、ツコツ古」ツ?、テ」ツつ津」ツ?ィテ」ツ?」テ」ツ?ヲ Point テ」ツ?ク
istream& operator >> ( istream &s, Point &a )
{
	double r, i;
	s >> r >> i;
	a = Point( r, i );
	return s;
}

// テ・ツ??ァツゥツ催ッツシツ暗」ツδ嘉」ツδε」ツδ暗ァツゥツ催ッツシツ?
double dot( const Point &a, const Point &b )
{
	return a.real() * b.real() + a.imag() * b.imag();
}

// テ・ツ、ツ姪ァツゥツ催ッツシツ暗」ツつッテ」ツδュテ」ツつケテァツゥツ催ッツシツ?
double cross( const Point &a, const Point &b )
{
	return a.real() * b.imag() - a.imag() * b.real();
}

// テァツ崢エテァツキツ?( p1, p2 ) テ」ツ?ィテァツつケ q テ」ツ?ョティツキツ敕ゥツ崢「
// include : cross
double distance_line_point( const Point &p1, const Point &p2, const Point &q )
{
	return abs( cross( p2 - p1, q - p1 ) ) / abs( ( p2 - p1 ) );
}

// テァツキツ堙・ツ按?( p1, p2 ) テ」ツ?ィテァツつケ q テ」ツ?ョティツキツ敕ゥツ崢「
// include : dot, distance_line_point
double distance_segment_point( const Point &p1, const Point &p2, const Point q )
{
	if ( EPS < dot( p2 - p1, q - p1 ) && EPS < dot( p1 - p2, q - p2 ) ) // テ・ツ楪づァツキツ堙」ツ?古、ツコツ、テ」ツつ湘」ツつ?
	{
		return distance_line_point( p1, p2, q );
	}
	else
	{
		return min( abs( p1 - q ), abs( p2 - q ) );
	}
}

// テァツキツ堙・ツ按?( p1, p2 ) テ」ツ?ィテ・ツ??( q, r ) テ」ツ?古、ツコツ、テ・ツキツョテ」ツ?凖」ツつ凝」ツ??
// include : distance_segment_point
bool segment_circle_intersect( const Point &p1, const Point &p2, const Point &q, const double r )
{
	if ( abs( p1 - q ) + EPS < r && abs( p2 - q ) + EPS < r )
	{
		return false;
	}
	else if ( r + EPS < abs( p1 - q ) && r + EPS < abs( p1 - q ) )
	{
		return distance_segment_point( p1, p2, q ) <= r + EPS;
	}
	else
	{
		return true;
	}
};

int main()
{
	cin.tie( 0 );
	ios::sync_with_stdio( false );

	for ( int n; cin >> n, n; )
	{
		vector<Point> walls( n );
		vector<double> rs( n );
		REP( i, 0, n )
		{
			cin >> walls[i] >> rs[i];
		}

		int m;
		cin >> m;
		REP( i, 0, m )
		{
			Point t, s;
			cin >> t >> s;

			bool safe = false;
			REP( j, 0, n )
			{
				safe |= segment_circle_intersect( t, s, walls[j], rs[j] );
			}
			cout << ( safe ? "Safe" : "Danger" ) << endl;
		}
	}

	return 0;
}
