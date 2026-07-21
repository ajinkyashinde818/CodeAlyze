unittest
{
	assert( [ "bac" ].parse.expand.solve == "Yes" );
	assert( [ "bab" ].parse.expand.solve == "No" );
	assert( [ "aaa" ].parse.expand.solve == "No" );
}



import std.algorithm;
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
	auto s = input.front.strip;
	return tuple( s );
}

auto solve( string s )
{
	auto ss = s.to!( dchar[] ).sort();
	return ss.equal( "abc" ) ? "Yes" : "No";
}
