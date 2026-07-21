unittest
{
	assert( [ "6", "1 1 1 2 2 3", "1 1 1 2 2 3" ].solve == "Yes\n2 2 3 1 1 1" );
	assert( [ "3", "1 1 2", "1 1 3" ].solve == "No" );
	assert( [ "4", "1 1 2 3", "1 2 3 3" ].solve == "Yes\n3 3 1 2" );
}



import std.algorithm;
import std.conv;
import std.range;
import std.stdio;

void main()
{
	stdin.byLineCopy.solve.writeln;
}

auto solve( Range )( Range input )
if( isInputRange!Range && is( ElementType!Range == string ) )
{
	auto n = input.front.to!( long );
	input.popFront;
	auto as = input.front.split.to!( long[] );
	input.popFront;
	auto bs = input.front.split.to!( long[] );
	
	// 可否を判定
	auto cs = new long[ n + 1 ];
	foreach( a, b; lockstep( as, bs ) )
	{
		cs[ a ]++;
		cs[ b ]++;
	}
	foreach( c; cs )
	{
		if( n < c ) return "No";
	}
	
	// a!=bになるように入れ替え
	for( auto i = 0L, j = 0L, k = 0L; i < n; i++ )
	{
		if( as[ i ] != bs[ i ] ) continue;
		if( as[ i ] != as[ k ] )
		{
			j = 0;
			k = i;
		}
		for( ; j < n; j++ )
		{
			if( as[ i ] != bs[ j ] && as[ j ] != bs[ i ] )
			{
				bs.swapAt( i, j );
				break;
			}
		}
	}
	return "Yes\n" ~ bs.to!( string[] ).join( " " );
}
