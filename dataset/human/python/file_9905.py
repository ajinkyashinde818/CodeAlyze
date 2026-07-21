import std.conv;
import std.stdio;
import std.array;
import std.range;
import std.string;
import std.algorithm;

void main()
{
	int sum = 0;
	
	foreach(_; 0..10) {
		sum += readln().chomp().to!int;
	}

	writeln(sum);
}
