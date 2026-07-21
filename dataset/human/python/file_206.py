unittest
{
//	assert( [ "3" ].parse.expand.solve == "Yes\n3\n2 1 2\n2 3 1\n2 2 3" );
	assert( [ "3" ].parse.expand.solve == "Yes\n3\n2 1 2\n2 1 3\n2 2 3" );
	assert( [ "4" ].parse.expand.solve == "No" );
}



import std.algorithm;
import std.conv;
import std.format;
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
	auto ansss = [ [ 1L ], [ 1L ] ];
	auto s = 1L;
	while( s < n )
	{
		auto k = ansss.length.signed;
		ansss.length++;
		for( auto i = 0L; i < k; i++ )
		{
			s++;
			ansss[ i ] ~= s;
			ansss[ k ] ~= s;
		}
	}
	if( s != n ) return "No";
	else         return format( "Yes\n%s\n%s", ansss.length, ansss.map!( ( a ) => format( "%s %s", a.length, a.to!( string[] ).join( " " ) ) ).join( "\n" ) );
}
