unittest
{
	assert( [ "29" ].parse.expand.solve == "Yes" );
	assert( [ "72" ].parse.expand.solve == "No" );
	assert( [ "91" ].parse.expand.solve == "Yes" );
}



import std.conv;
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
	return tuple( n );
}

auto solve( long n )
{
	return ( n % 10 == 9 || n / 10 == 9 ) ? "Yes" : "No";
}
