unittest
{
	assert( [ "CODEFESTIVAL" ].parse.expand.solve == "CODE" );
	assert( [ "CODEFESTIVALFESTIVAL" ].parse.expand.solve == "CODEFESTIVAL" );
	assert( [ "YAKINIKUFESTIVAL" ].parse.expand.solve == "YAKINIKU" );
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
	auto s = input.front.to!( dchar[] );
	return tuple( s );
}

auto solve( dchar[] s )
{
	return s[ 0 .. $ - 8 ];
}
