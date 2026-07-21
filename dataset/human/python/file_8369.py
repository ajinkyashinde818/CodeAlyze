unittest
{
	assert( [ "20 3", "5 10 15" ].parse.expand.solve == 10 );
	assert( [ "20 3", "0 5 15" ].parse.expand.solve == 10 );
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
	auto kn = input.front.split.to!( long[] );
	input.popFront;
	auto as = input.front.split.to!( long[] );
	return tuple( kn[ 0 ], kn[ 1 ], as );
}

auto solve( long k, long n, long[] as )
{
	auto ans = long.max;
	as.sort();
	foreach( i, a; as )
	{
		ans = min( ans, as[ n - 1 + i ] - a );
		as ~= k + a;
	}
	return ans;
}
