unittest
{
	assert( [ "A B" ].parse.expand.solve == "<" );
	assert( [ "E C" ].parse.expand.solve == ">" );
	assert( [ "F F" ].parse.expand.solve == "=" );
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
	auto xy = input.front.split.to!( string[] );
	return tuple( xy[ 0 ], xy[ 1 ] );
}

auto solve( string x, string y )
{
	if( x < y ) return "<";
	if( y < x ) return ">";
	return "=";
}
