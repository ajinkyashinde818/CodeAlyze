unittest
{
	assert( [ "24" ].parse.expand.solve == 3 );
	assert( [ "1" ].parse.expand.solve == 0 );
	assert( [ "64" ].parse.expand.solve == 3 );
	assert( [ "1000000007" ].parse.expand.solve == 1 );
	assert( [ "997764507000" ].parse.expand.solve == 7 );
}



import std.algorithm;
import std.conv;
import std.range;
import std.stdio;
import std.typecons;

void main()
{
	stdin.byLineCopy.parse.expand.solve.writeln;
}

auto parse( Range )( Range input )
if( isInputRange!Range && is( ElementType!Range == string ) )
{
	auto n = input.front.to!( long );
	return tuple( n );
}

auto solve( long n )
{
	auto ans = 0L;
	foreach( pc; n.primefactorize.group )
	{
		for( auto i = 1L; i <= pc[ 1 ]; i++ )
		{
			pc[ 1 ] -= i;
			ans++;
		}
	}
	return ans;
}

// 素数列
auto primes( long x )
{
	Appender!( long[] ) ps;
	if( x < 2 ) return ps.data;
	
	auto cs = new bool[]( x + 1 );
	ps ~= 2L;
	for( auto i = 3L; i * i < cs.length; i += 2 )
	{
		if( cs[ i ] ) continue;
		for( auto j = i; i * j < cs.length; j++ )
		{
			cs[ i * j ] = true;
		}
	}
	for( auto i = 3L; i < cs.length; i += 2 )
	{
		if( !cs[ i ] ) ps ~= i;
	}
	return ps.data;
}

// 素因数分解
auto primefactorize( long x )
{
	Appender!( long[] ) fs;
	if( x < 2 ) return fs.data;
	
	auto s = cast( long ) x ^^ 0.5L;
	foreach( p; s.primes )
	{
		while( x % p == 0 )
		{
			x /= p;
			fs ~= p;
		}
		if( x < 2 ) break;
	}
	if( 2 <= x ) fs ~= x;
	return fs.data;
}
