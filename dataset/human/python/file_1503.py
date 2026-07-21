unittest
{
	assert( [ "3 2", "#.#", ".#.", "#.#", "#.", ".#" ].parse.expand.solve == "Yes" );
	assert( [ "4 1", "....", "....", "....", "....", "#" ].parse.expand.solve == "No" );
	
	assert( [ "3 2", "..#", ".#.", "#.#", "#.", ".#" ].parse.expand.solve == "Yes" );		// 追加ケース
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
	auto nm = input.front.split.to!( long[] );
	auto ass = new dchar[][]( nm[ 0 ] );
	foreach( ref as; ass )
	{
		input.popFront;
		as = input.front.to!( dchar[] );
	}
	auto bss = new dchar[][]( nm[ 1 ] );
	foreach( ref bs; bss )
	{
		input.popFront;
		bs = input.front.to!( dchar[] );
	}
	return tuple( ass, bss );
}

auto solve( dchar[][] ass, dchar[][] bss )
{
	for( auto ai = 0L; ai <= ass.length - bss.length; ai++ )
	{
		LOOP: for( auto aj = 0L; aj <= ass[ 0 ].length - bss[ 0 ].length; aj++ )
		{
			for( auto bi = 0L; bi < bss.length; bi++ )
			{
				for( auto bj = 0L; bj < bss[ 0 ].length; bj++ )
				{
					if( ass[ ai + bi ][ aj + bj ] != bss[ bi ][ bj ] ) continue LOOP;
				}
			}
			
			return "Yes";
		}
	}
	
	return "No";
}
