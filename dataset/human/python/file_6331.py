unittest
{
	assert( [ "12" ].solve == 1 );
	assert( [ "5" ].solve == 0 );
	assert( [ "1000000000000000000" ].solve == 124999999999999995 );
}

unittest
{
	// 追加ケース
	import std.algorithm;
	import std.bigint;
	BigInt test( long n )
	{
		if( n < 2 ) return BigInt( 1 );
		else        return n * test( n - 2 );
	}
	foreach( i; 0L .. 3001L )
	{
		auto k = test( i ).to!( string );
		assert( [ i.to!( string ) ].solve == k.length.signed - k.retro.find!( ( a ) => a != '0' ).walkLength );
	}
}



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
	
	// 奇数の場合は末尾が0にならない
	if( n % 2 == 1 ) return 0L;
	
	// 素因数分解して2と5がセットにできる数だけ末尾の0が増える
	// 2はいっぱいあるので、5の数だけ数えれば良い
	auto ans = 0L;
	for( auto i = 10L; i <= n; i *= 5 )
	{
		ans += n / i;
	} 
	return ans;
}
