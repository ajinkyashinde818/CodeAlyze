unittest
{
	assert( [ "3 2", "1 2", "2 3" ].parse.expand.solve == "POSSIBLE" );
	assert( [ "4 3", "1 2", "2 3", "3 4" ].parse.expand.solve == "IMPOSSIBLE" );
	assert( [ "100000 1", "1 99999" ].parse.expand.solve == "IMPOSSIBLE" );
	assert( [ "5 5", "1 3", "4 5", "2 3", "2 4", "1 4" ].parse.expand.solve == "POSSIBLE" );
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
	auto nm = input.front.split.to!( long[] );
	auto abs = new long[ 2 ][ nm[ 1 ] ];
	foreach( ref ab; abs )
	{
		input.popFront;
		ab = input.front.split.to!( long[] );
	}
	return tuple( nm[ 0 ], abs );
}

auto solve( long n, long[ 2 ][] abs )
{
	// 島1から他の島へ行く定期船を調べる
	auto s1 = abs.filter!( ( ab ) => ab[ 0 ] == 1 ).map!( ( ab ) => ab[ 1 ] ).array;
	s1.sort();
	
	// 他の島から島Nへ行く定期船を調べる
	auto s2 = abs.filter!( ( ab ) => ab[ 1 ] == n ).map!( ( ab ) => ab[ 0 ] ).array;
	s2.sort();
	
	// 島1と島Nの両方から行ける島を調べる
	while( !s1.empty && !s2.empty )
	{
		if( s1.front == s2.front ) return "POSSIBLE";
		
		if( s1.front < s2.front ) s1.popFront;
		else                      s2.popFront;
	}
	
	return "IMPOSSIBLE";
}
