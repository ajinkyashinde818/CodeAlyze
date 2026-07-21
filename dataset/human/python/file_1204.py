unittest
{
	assert( [ "6", "1 2 3 4 5 6" ].parse.expand.solve == 1 );
	assert( [ "2", "10 -10" ].parse.expand.solve == 20 );
}



import std.algorithm;
import std.conv;
import std.math;
import std.range;
import std.stdio;
import std.string;
import std.typecons;

void main()
{
	stdin.byLineCopy.parse.expand.solve.writeln;
}

auto parse( Range )( Range input )
if( isInputRange!Range && is( ElementType!Range == string ) )
{
	auto n = input.front.strip.to!( long );
	input.popFront;
	auto as = input.front.split.to!( long[] );
	return tuple( as );
}

auto solve( long[] as )
{
	auto x = as[ 0 ];
	auto y = as[ 1 .. $ ].sum;
	auto d = ( x - y ).abs;
	foreach( a; as[ 1 .. $ - 1 ] )
	{
		x += a;
		y -= a;
		d = min( d, ( x - y ).abs );
	}
	return d;
}
