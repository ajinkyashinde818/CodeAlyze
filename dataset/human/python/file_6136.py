unittest
{
	assert( [ "3 1 4" ].parse.expand.solve == 5 );
	assert( [ "5 2 9" ].parse.expand.solve == 10 );
	assert( [ "8 8 1" ].parse.expand.solve == 9 );
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
	auto abc = input.front.split.to!( long[] );
	return tuple( abc[ 0 ], abc[ 1 ], abc[ 2 ] );
}

auto solve( long a, long b, long c )
{
	// 毒クッキーと解毒クッキーを交互に食べる
	if( c - 1 <= b + a ) return c + b;							// 毒クッキーを食べきれるパターン
	else                 return c + b - ( c - 1 - b - a );		// 毒クッキーを食べきれないパターン
}
