unittest
{
	assert( [ "36" ].parse.expand.solve == 8 );
	assert( [ "91" ].parse.expand.solve == 3 );
	assert( [ "314159265358979323846264338327950288419716939937551058209749445923078164062862089986280348253421170" ].parse.expand.solve == 243 );
}



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
	auto n = input.front.map!( ( a ) => ( a - '0' ).to!( long ) ).retro.array;
	return tuple( n );
}

auto solve( long[] n )
{
	// dp[ 左からi桁目 ][ 繰り上げフラグ ] = 紙幣の枚数
	auto dp = new long[][]( n.length, 2 );
	dp[ 0 ][ 0 ] = n.front;						// 支払いが増える
	dp[ 0 ][ 1 ] = ( 10 - n.front ) + 1;		// お釣り＋繰り上げ支払い1枚が増える
	n.popFront;
	foreach( i, d; n )
	{
		// i-1桁目で繰り上げせず、i桁目で繰り上げしない場合（支払いが増える）
		dp[ i + 1 ][ 0 ] = dp[ i ][ 0 ] + d;
		
		// i-1桁目で繰り上げして、i桁目で繰り上げしない場合（支払いが増える）
		if( d < 9 ) dp[ i + 1 ][ 0 ] = min( dp[ i + 1 ][ 0 ], dp[ i ][ 1 ] + d );
		
		// i-1桁目で繰り上げして、i桁目で繰り上げする場合（お釣りが増える）
		dp[ i + 1 ][ 1 ] = dp[ i ][ 1 ] + ( 10 - ( d + 1 ) );
		
		// i-1桁目で繰り上げせず、i桁目で繰り上げする場合（お釣り＋繰り上げ支払い1枚が増える）
		if( 0 < d ) dp[ i + 1 ][ 1 ] = min( dp[ i + 1 ][ 1 ], dp[ i ][ 0 ] + ( 10 - d ) + 1 );
	}
	return dp[ $ - 1 ].reduce!min;
}
