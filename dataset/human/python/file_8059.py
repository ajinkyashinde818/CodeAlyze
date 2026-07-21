unittest
{
	assert( [ "2 2" ].parse.expand.solve == 6 );
	assert( [ "5 15" ].parse.expand.solve == 1 );
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
	auto ks = input.front.split.to!( long[] );
	return tuple( ks[ 0 ], ks[ 1 ] );
}

auto solve( long k, long s )
{
	auto ans = 0L;
	
	for( auto x = 0L; x <= k && x <= s; x++ )
	{
		for( auto y = 0L; y <= k && x + y <= s; y++ )
		{
			auto z = s - ( x + y );
			ans += ( z <= k );
		}
	}
	
	return ans;
}
