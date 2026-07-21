unittest
{
	assert( [ "yx", "axy" ].parse.expand.solve == "Yes" );
	assert( [ "ratcode", "atlas" ].parse.expand.solve == "Yes" );
	assert( [ "cd", "abc" ].parse.expand.solve == "No" );
	assert( [ "w", "ww" ].parse.expand.solve == "Yes" );
	assert( [ "zzz", "zzz" ].parse.expand.solve == "No" );
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
	input.popFront;
	auto t = input.front.strip;
	return tuple( s, t );
}

auto solve( string s, string t )
{
	auto ss = s.to!( dchar[] ).sort();
	auto tt = t.to!( dchar[] ).sort!( ( a, b ) => b < a )();
	
	return ( ss.cmp( tt ) < 0 ) ? "Yes" : "No";
}
