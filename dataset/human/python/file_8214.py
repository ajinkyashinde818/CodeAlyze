unittest
{
	assert( [ "FTFFTFFF", "4 2" ].parse.expand.solve == "Yes" );
	assert( [ "FTFFTFFF", "-2 -2" ].parse.expand.solve == "Yes" );
	assert( [ "FF", "1 0" ].parse.expand.solve == "No" );
	assert( [ "TF", "1 0" ].parse.expand.solve == "No" );
	assert( [ "FFTTFF", "0 0" ].parse.expand.solve == "Yes" );
	assert( [ "TTTT", "1 0" ].parse.expand.solve == "No" );
}



import std.algorithm;
import std.conv;
import std.math;
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
	auto xy = input.front.split.to!( long[] );
	return tuple( s, xy[ 0 ], xy[ 1 ] );
}

auto solve( dchar[] s, long x, long y )
{
	auto gs = s.group;
	
	// 最初は必ず右に移動するので先に処理しておく
	if( gs.front[ 0 ] == 'F' )
	{
		x -= gs.front[ 1 ];
		gs.popFront;
	}
	
	// 横移動と縦移動を分別
	long[] as;
	long[] bs;
	long at;
	long bt;
	auto h = true;
	foreach( g; gs )
	{
		if( g[ 0 ] == 'F' )
		{
			if( h )
			{
				as ~= g[ 1 ];
				at += g[ 1 ];
			}
			else
			{
				bs ~= g[ 1 ];
				bt += g[ 1 ];
			}
		}
		else
		{
			if( g[ 1 ] % 2 ) h = !h;
		}
	}
	if( at < x.abs || bt < y.abs ) return "No";		// 全力で近づいても届かないのでダメ
	
	// 横移動を右と左に振り分けてちょうどxに止まれるか判定
	if( !solve2( as, at, x ) ) return "No";
	
	// 縦移動を上と下に振り分けてちょうどyに止まれるか判定
	if( !solve2( bs, bt, y ) ) return "No";
	
	return "Yes";
}

auto solve2( long[] ds, long dt, long g )
{
	auto dp = new bool[][]( 1 + ds.length, dt * 2 + 1 );
	dp[ 0 ][ dt ] = true;
	foreach( i, d; ds )
	{
		for( auto p = 0L; p < dp[ i ].length; p++ )
		{
			if( !dp[ i ][ p ] ) continue;
			dp[ i + 1 ][ p - d ] = true;
			dp[ i + 1 ][ p + d ] = true;
		}
	}
	return dp[ $ - 1 ][ dt + g ];
}
