unittest
{
//	assert( [ "4 2 3" ].parse.expand.solve == "1 2 3 4" );
//	assert( [ "5 3 100" ].parse.expand.solve == "50 50 50 30 70" );
}



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
	auto nks = input.front.split.to!( long[] );
	return tuple( nks[ 0 ], nks[ 1 ], nks[ 2 ] );
}

auto solve( long n, long k, long s )
{
	auto anss = new long[ n ];
	auto t = 10L ^^ 9 - ( s == 10L ^^ 9 );
	foreach( i, ref ans; anss )
	{
		ans = ( i < k ) ? s : t;
	}
	return anss.to!( string[] ).join( ' ' );
}
