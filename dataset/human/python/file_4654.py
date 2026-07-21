unittest
{
	assert( [ "2", "0", "10", "20", "30" ].parse.expand.solve == 2 );
	assert( [ "3", "3", "10", "8", "7", "12", "5" ].parse.expand.solve == 1 );
	
	assert( [ "4", "1", "2", "4", "7", "3", "5", "6", "8" ].parse.expand.solve == 4 );		// 追加ケース
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
	auto n = input.front.to!( long );
	auto as = new long[ n ];
	foreach( ref a; as )
	{
		input.popFront;
		a = input.front.to!( long );
	}
	auto bs = new long[ n ];
	foreach( ref b; bs )
	{
		input.popFront;
		b = input.front.to!( long );
	}
	return tuple( as, bs );
}

auto solve( long[] as, long[] bs )
{
	as.sort();
	bs.sort();
	
	// aとbを順番に並べる
	auto gs = [ tuple( ( as.front < bs.front ) ? 'a' : 'b', 0L ) ];
	while( !as.empty || !bs.empty )
	{
		if( bs.empty || ( !as.empty && as.front < bs.front ) )
		{
			if( gs.back[ 0 ] == 'a' ) gs.back[ 1 ]++;
			else                      gs ~= tuple( 'a', 1L );
			as.popFront;
		}
		else
		{
			if( gs.back[ 0 ] == 'b' ) gs.back[ 1 ]++;
			else                      gs ~= tuple( 'b', 1L );
			bs.popFront;
		}
	}
	
	// 接続のパターン数を計算
	auto ans = 1L;
	auto f = gs.front;
	gs.popFront;
	foreach( g; gs )
	{
		if( f[ 0 ] == g[ 0 ] )
		{
			f[ 1 ] += g[ 1 ];
			continue;
		}
		
		// ケーブルを左から右に繋げるパターンを列挙（逆走するパターンはケーブル長が伸びてしまうのでNG）
		auto p = f[ 1 ].permutationMod( min( f[ 1 ], g[ 1 ] ) );
		ans = ans.mulMod( p );
		f[ 0 ] = ( f[ 1 ] < g[ 1 ] ) ? g[ 0 ] : f[ 0 ];
		f[ 1 ] = abs( f[ 1 ] - g[ 1 ] );
	}
	return ans;
}

// 掛け算
auto mulMod( long MOD = 10L ^^ 9 + 7 )( long x, long y )
{
	return x * y % MOD;
}

// 割り算
auto divMod( long MOD = 10L ^^ 9 + 7 )( long x, long y )
{
	return x * y.powMod!MOD( MOD - 2 ) % MOD;
}

// べき乗
auto powMod( long MOD = 10L ^^ 9 + 7 )( long x, long y )
{
	auto a = 1L;
	for( ; 0 < y; y >>= 1 )
	{
		if( y & 1 ) a = a * x % MOD;
		x = x ^^ 2 % MOD;
	}
	return a;
}

// 階乗
auto factorialMod( long MOD = 10L ^^ 9 + 7 )( long x )
{
	static memo = [ 1L ];
	if( memo.length <= x )
	{
		auto i = memo.length;
		memo.length = x + 1;
		for( ; i <= x; i++ ) memo[ i ] = memo[ i - 1 ] * i % MOD;
	}
	return memo[ x ];
}

// 順列数
auto permutationMod( long MOD = 10L ^^ 9 + 7 )( long x, long y )
{
	return x.factorialMod!MOD.divMod!MOD( ( x - y ).factorialMod!MOD );
}
