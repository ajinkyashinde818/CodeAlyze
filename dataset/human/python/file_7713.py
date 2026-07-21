unittest
{
	assert( [ "1000" ].parse.expand.solve == "ABC" );
	assert( [ "2000" ].parse.expand.solve == "ARC" );
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
	auto x = input.front.to!( long );
	return tuple( x );
}

auto solve( long x )
{
	return ( x < 1200 ) ? "ABC" : "ARC";
}
