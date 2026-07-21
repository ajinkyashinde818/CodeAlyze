unittest
{
	assert( [ "4", "abcd" ].parse.expand.solve == 15 );
	assert( [ "3", "baa" ].parse.expand.solve == 5 );
	assert( [ "5", "abcab" ].parse.expand.solve == 17 );
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
	input.popFront;
	auto s = input.front.to!( dchar[] );
	return tuple( s );
}

auto solve( dchar[] s )
{
	const MOD = 10L ^^ 9 + 7;
	
	// 文字ごとに個数を集計して、文字ごとのケース数（i番目を選ぶor何も選ばない）を掛け算して、全文字選ばない1ケースを除外
	return reduce!( ( a, b ) => a * ( b[ 1 ] + 1 ) % MOD )( 1L, s.sort().group ) - 1;
}
