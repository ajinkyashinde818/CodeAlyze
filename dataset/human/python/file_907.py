unittest
{
	assert( [ "3 20", "2 80", "9 120", "16 1" ].parse.expand.solve == 191 );
	assert( [ "3 20", "2 80", "9 1", "16 120" ].parse.expand.solve == 192 );
	assert( [ "1 100000000000000", "50000000000000 1" ].parse.expand.solve == 0 );
	assert( [ "15 10000000000", "400000000 1000000000", "800000000 1000000000", "1900000000 1000000000", "2400000000 1000000000", "2900000000 1000000000", "3300000000 1000000000", "3700000000 1000000000", "3800000000 1000000000", "4000000000 1000000000", "4100000000 1000000000", "5200000000 1000000000", "6600000000 1000000000", "8000000000 1000000000", "9300000000 1000000000", "9700000000 1000000000" ].parse.expand.solve == 6500000000 );
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
	auto nc = input.front.split.to!( long[] );
	auto xvs = new long[ 2 ][ nc[ 0 ] ];
	foreach( ref xv; xvs )
	{
		input.popFront;
		xv = input.front.split.to!( long[] );
	}
	return tuple( nc[ 1 ], xvs );
}

auto solve( long c, long[ 2 ][] xvs )
{
	// 時計回りに食べたときのカロリーの最大値を計算
	auto rfs = new long[ 1 + xvs.length ];		// 片道
	auto rbs = new long[ 1 + xvs.length ];		// 往復
	for( auto i = 0L, t = 0L; i < xvs.length; i++ )
	{
		t += xvs[ i ][ 1 ];
		rfs[ i + 1 ] = max( rfs[ i ], t - xvs[ i ][ 0 ] );
		rbs[ i + 1 ] = max( rbs[ i ], t - xvs[ i ][ 0 ] * 2 );
	}
	
	// 反時計回りに食べたときのカロリーの最大値を計算
	auto lfs = new long[ 1 + xvs.length ];		// 片道
	auto lbs = new long[ 1 + xvs.length ];		// 往復
	for( auto i = 0L, t = 0L; i < xvs.length; i++ )
	{
		t += xvs[ $ - 1 - i ][ 1 ];
		lfs[ i + 1 ] = max( lfs[ i ], t - ( c - xvs[ $ - 1 - i ][ 0 ] ) );
		lbs[ i + 1 ] = max( lbs[ i ], t - ( c - xvs[ $ - 1 - i ][ 0 ] ) * 2 );
	}
	
	// 途中まで食べた後に引き返して反対側を食べたときのカロリーの最大値を計算
	auto ans = 0L;
	foreach( rb, lf, lb, rf; lockstep( rbs, lfs.retro, lbs, rfs.retro ) )
	{
		ans = max( ans, rb + lf, lb + rf );
	}
	return ans;
}
