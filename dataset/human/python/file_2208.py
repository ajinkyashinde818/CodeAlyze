unittest
{
	assert( [ "2 700", "3 500", "5 800" ].solve == 3 );
	assert( [ "2 2000", "3 500", "5 800" ].solve == 7 );
	assert( [ "2 400", "3 500", "5 800" ].solve == 2 );
	assert( [ "5 25000", "20 1000", "40 1000", "50 1000", "30 1000", "1 1000" ].solve == 66 );
}



import std.algorithm;
import std.conv;
import std.format;
import std.range;
import std.stdio;

void main()
{
	stdin.byLineCopy.solve.writeln;
}

auto solve( Range )( Range input )
if( isInputRange!Range && is( ElementType!Range == string ) )
{
	auto d = 0L;
	auto g = 0L;
	input.front.formattedRead!"%s %s"( d, g );
	auto pcs = new long[ 2 ][ d ];
	foreach( ref pc; pcs )
	{
		input.popFront;
		pc = input.front.split.to!( long[] );
	}
	
	auto as = new long[ d ];
	foreach( i, ref a, pc; lockstep( as, pcs ) )
	{
		a = 100L * ( 1 + i.signed ) * pc[ 0 ] + pc[ 1 ];
	}
	
	auto ans = long.max;
	foreach( b; 0L .. 1L << d )
	{
		auto pt = 0L;
		auto ct = 0L;
		auto m = 0L;
		foreach( i, a; as )
		{
			if( b & ( 1L << i ) )
			{
				pt += pcs[ i ][ 0 ];
				ct += a;
			}
			else
			{
				m = i;
			}
		}
		
		if( ct < g )
		{
			auto u = 100L * ( 1 + m );
			auto p = ( g - ct + u - 1 ) / u;
			if( pcs[ m ][ 0 ] < p ) continue;
			pt += p;
			ct += u * p;
		}
		
		ans = min( ans, pt );
	}
	return ans;
}
