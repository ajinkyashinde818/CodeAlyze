unittest
{
	assert( [ "1 2 3 4" ].parse.expand.solve == 4 );
	assert( [ "13 1 4 3000" ].parse.expand.solve == 87058 );
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
	auto rgbn = input.front.split.to!( long[] );
	return tuple( rgbn[ 0 .. 3 ], rgbn[ 3 ] );
}

auto solve( long[] rgb, long n )
{
	rgb.sort!( ( a, b ) => b < a );
	
	auto ans = 0L;
	for( auto a = 0L; a <= n; a += rgb[ 0 ] )
	{
		for( auto b = 0L; a + b <= n; b += rgb[ 1 ] )
		{
			ans += ( ( n - a - b ) % rgb[ 2 ] == 0 );
		}
	}
	return ans;
}
