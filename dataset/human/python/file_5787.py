unittest
{
	assert( [ "3", "3 1 2", "2 5 4", "3 6" ].parse.expand.solve == 14 );
	assert( [ "4", "2 3 4 1", "13 5 8 24", "45 9 15" ].parse.expand.solve == 74 );
	assert( [ "2", "1 2", "50 50", "50" ].parse.expand.solve == 150 );
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
	input.popFront;
	auto as = input.front.split.to!( long[] );
	as[] -= 1;
	input.popFront;
	auto bs = input.front.split.to!( long[] );
	input.popFront;
	auto cs = input.front.split.to!( long[] );
	return tuple( as, bs, cs );
}

auto solve( long[] as, long[] bs, long[] cs )
{
	auto ans = 0L;
	auto p = long.max;
	foreach( a; as )
	{
		ans += bs[ a ];
		if( p + 1 == a ) ans += cs[ p ];
		p = a;
	}
	return ans;
}
