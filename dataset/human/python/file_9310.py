unittest
{
	assert( [ "4 5", "3 2 4 1" ].parse.expand.solve == 4 );
	assert( [ "6 727202214173249351", "6 5 2 5 3 2" ].parse.expand.solve == 2 );
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
	auto nk = input.front.split.to!( long[] );
	input.popFront;
	auto as = input.front.split.to!( long[] );
	as[] -= 1;
	return tuple( nk[ 1 ], as );
}

auto solve( long k, long[] as )
{
	auto ds = new long[ as.length ];
	ds[] = -1;
	auto p = 0L;
	for( auto i = 0L; i < k; i++ )
	{
		if( 0 <= ds[ p ] )
		{
			// ループを検知したのでシミュレーション省略
			auto l = i - ds[ p ];
			i += ( ( k - i ) / l ) * l;
		}
		if( i == k ) break;
		
		// 次に進む
		ds[ p ] = i;
		p = as[ p ];
	}
	return p + 1;
}
