unittest
{
	assert( [ "xabxa" ].parse.expand.solve == 2 );
	assert( [ "ab" ].parse.expand.solve == -1 );
	assert( [ "a" ].parse.expand.solve == 0 );
	assert( [ "oxxx" ].parse.expand.solve == 3 );
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
	auto ans = 0L;
	auto l = 0L;
	auto r = s.length.signed - 1;
	while( l < r )
	{
		if( s[ l ] == s[ r ] )
		{
			l++;
			r--;
		}
		else if( s[ l ] == 'x' && s[ r ] != 'x' )
		{
			ans++;
			l++;
		}
		else if( s[ l ] != 'x' && s[ r ] == 'x' )
		{
			ans++;
			r--;
		}
		else
		{
			return -1;
		}
	}
	return ans;
}
