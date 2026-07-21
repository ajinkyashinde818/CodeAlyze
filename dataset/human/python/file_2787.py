unittest
{
	assert( [ "3 5", "3 3", "4 4", "2 5" ].parse.expand.solve == 8 );
	assert( [ "3 6", "3 3", "4 4", "2 5" ].parse.expand.solve == 9 );
	assert( [ "7 14", "10 5", "7 4", "11 4", "9 8", "3 6", "6 2", "8 9" ].parse.expand.solve == 32 );
}



import core.bitop;
import std.algorithm;
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
	auto nk = input.front.split.to!( long[] );
	auto abs = new long[ 2 ][ nk[ 0 ] ];
	foreach( ref ab; abs )
	{
		input.popFront;
		ab = input.front.split.to!( long[] );
	}
	return tuple( nk[ 1 ], abs );
}

auto solve( long k, long[ 2 ][] abs )
{
	// i+1桁目を繰り下げしてi桁目以下が0でも1でもいいビットマスクを作成
	auto ms = [ k ];
	foreach( i; 0L .. k.bsr )
	{
		auto b = 1L << i;
		if( ms.back & b ) continue;
		ms ~= ms.back - b;
	}
	
	// ビットマスクごとに価値の総和を計算
	auto ans = 0L;
	foreach( m; ms )
	{
		auto t = 0L;
		foreach( ab; abs )
		{
			if( ( ab[ 0 ] & ~m ) == 0 ) t += ab[ 1 ];
		}
		ans = max( ans, t );
	}
	return ans;
}
