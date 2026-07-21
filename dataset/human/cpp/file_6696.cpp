#include<iostream>
#include<complex>

typedef std::complex<double> P;

const double EPS = 1e-10;

double dot( const P& a, const P& b )
{
	return std::real( std::conj( a ) * b );
}

double cross( const P& a, const P& b )
{
	return std::imag( std::conj( a ) * b );
}

// 線分abと点cの距離
double dist( const P& a, const P& b, const P& c )
{
	if( dot( b - a, c - a ) < EPS )
		return abs( c - a );
	if( dot( a - b, c - b ) < EPS )
		return abs( c - b );

	return abs( cross( b - a, c - a ) ) / abs( b - a );
}

int n;
P wpt[100];
double r[100];

std::istream& operator>> ( std::istream& in, P& p )
{
	if( in )
	{
		double x, y;
		in >> x >> y;
		p = P( x, y );
	}

	return in;
}

int main()
{
	while( std::cin >> n, n )
	{
		for( int i = 0; i != n; ++i )
			std::cin >> wpt[i] >> r[i];

		int m;
		std::cin >> m;
		for( int i = 0; i != m; ++i )
		{
			P s, t;
			std::cin >> s >> t;

			for( int j = 0; j != n; ++j )
			{
				if( !( abs( s - wpt[j] ) < r[j] && abs( t - wpt[j] ) < r[j] ) && dist( s, t, wpt[j] ) <= r[j] )
				{
					std::cout << "Safe" << std::endl;
					break;
				}
				else if( j == n - 1 )
					std::cout << "Danger" << std::endl;
			}
		}
	}

	return 0;
}
