unittest
{
	assert( [ "3", "1 2 3" ].parse.expand.solve == 5 );
	assert( [ "12", "161735902 211047202 430302156 450968417 628894325 707723857 731963982 822804784 880895728 923078537 971407775 982631932" ].parse.expand.solve == 750927044 );
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
	auto xs = input.front.split.to!( long[] );
	return tuple( xs );
}

auto solve( long[] xs )
{
	// 階乗を事前計算
	xs.length.factorialMod;
	
	// xs[i]からxs[i+1]の間をスライム[i-j..i+1)が通る確率を計算
	// xs[i]からxs[i+1]の間をスライム[i-j]が通る確率＝スライム[i-j..i+1)のうちスライム[i-j]が最後に選ばれるパターン÷全パターン
	auto ps = new long[ xs.length.signed ];
	foreach( j; 1L .. ps.length.signed )
	{
		auto p = ( j - 1 ).factorialMod.divMod( j.factorialMod );
		ps[ j ] = ps[ j - 1 ].addMod( p );
	}
	ps.popFront;
	
	// xs[i]からxs[i+1]の間をスライム[0..i+1)が移動するときの距離の総和の期待値を計算して合計
	auto ans = 0L;
	foreach( i, p; ps )
	{
		auto d = xs[ i + 1 ] - xs[ i ];
		ans = ans.addMod( p.mulMod( d ) );
	}
	
	// 期待値を距離の総和に戻したのが答え
	return ans.mulMod( ( xs.length.signed - 1 ).factorialMod );
}

// 足し算
auto addMod( long MOD = 10L ^^ 9 + 7 )( long x, long y )
{
	return ( x + y ) % MOD;
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
