unittest
{
	assert( [ "2 2919" ].parse.expand.solve == 3719 );
	assert( [ "22 3051" ].parse.expand.solve == 3051 );
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
	auto nr = input.front.split.to!( long[] );
	return tuple( nr[ 0 ], nr[ 1 ] );
}

auto solve( long n, long r )
{
	return ( n < 10 ) ? r + 100 * ( 10 - n ) : r;
}
