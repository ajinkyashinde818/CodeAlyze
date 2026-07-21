unittest
{
	assert( [ "2 3" ].parse.expand.solve == 6 );
	assert( [ "123 456" ].parse.expand.solve == 18696 );
	assert( [ "100000 99999" ].parse.expand.solve == 9999900000 );
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
	auto ab = input.front.split.to!( long[] );
	return tuple( ab[ 0 ], ab[ 1 ] );
}

auto solve( long a, long b )
{
	return lcm( a, b );
}

// 最小公倍数
auto lcm( long x, long y )
{
	import std.numeric;
	return x * y / x.gcd( y );
}
