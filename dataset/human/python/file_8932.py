unittest
{
	assert( [ "erasedream" ].parse.expand.solve == "YES" );
	assert( [ "dreameraser" ].parse.expand.solve == "YES" );
	assert( [ "dreamerer" ].parse.expand.solve == "NO" );
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
	auto s = input.front;
	return tuple( s );
}

auto solve( string s )
{
	LOOP: while( 0 < s.length )
	{
		foreach( w; [ "dream", "dreamer", "erase", "eraser" ] )
		{
			if( w.length <= s.length && s[ $ - w.length .. $ ] == w )
			{
				s.length -= w.length;
				continue LOOP;
			}
		}
		return "NO";
	}
	return "YES";
}
