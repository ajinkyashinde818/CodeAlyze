unittest
{
	assert( [ "a", "4", "2 1 p", "1", "2 2 c", "1" ].parse.expand.solve == "cpa" );
	assert( [ "a", "6", "2 2 a", "2 1 b", "1", "2 2 c", "1", "1" ].parse.expand.solve == "aabc" );
	assert( [ "y", "1", "2 1 x" ].parse.expand.solve == "xy" );
}



import std.container;
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
	input.popFront;
	auto q = input.front.to!( long );
	auto qss = new dchar[][][ q ];
	foreach( ref qs; qss )
	{
		input.popFront;
		qs = input.front.split.to!( dchar[][] );
	}
	return tuple( s, qss );
}

auto solve( dchar[] s, dchar[][][] qss )
{
	auto queue = DList!dchar( s );
	auto r = false;
	foreach( qs; qss )
	{
		final switch( qs[ 0 ] )
		{
			case "1":
				r = !r;
				break;
			
			case "2":
				if( ( !r && qs[ 1 ] == "1" ) || ( r && qs[ 1 ] == "2" ) ) queue.insertFront( qs[ 2 ] );
				else                                                      queue.insertBack( qs[ 2 ] );
				break;
		}
	}
	return r ? queue[].retro.array : queue[].array;
}
