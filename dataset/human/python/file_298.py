unittest
{
	assert( [ "3", "-10 5 -4" ].solve == 19 );
	assert( [ "5", "10 -4 -8 -11 3" ].solve == 30 );
	assert( [ "11", "-1000000000 1000000000 -1000000000 1000000000 -1000000000 0 1000000000 -1000000000 1000000000 -1000000000 1000000000" ].solve == 10000000000 );
}



import std.algorithm;
import std.conv;
import std.math;
import std.range;
import std.stdio;

void main()
{
	stdin.byLineCopy.solve.writeln;
}

auto solve( Range )( Range input )
if( isInputRange!Range && is( ElementType!Range == string ) )
{
	auto n = input.front.to!( long );
	input.popFront;
	auto as = input.front.split.to!( long[] );
	
	auto ans = 0L;
	auto c = 0L;
	auto m = long.max;
	foreach( a; as )
	{
		auto aa = a.abs;
		ans += aa;
		c += ( a < 0 );
		m = min( m, aa );
	}
	if( c % 2 ) ans -= m * 2;
	return ans;
}
