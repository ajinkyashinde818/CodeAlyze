import std.stdio;
import std.algorithm;
import std.array;
import std.conv;
import std.datetime;
import std.numeric;
import std.math;
import std.string;

string my_readln() { return chomp(readln()); }

void main()
{//try{
	auto tokens = split(my_readln());
	auto A = to!ulong(tokens[0]);
	auto B = to!ulong(tokens[1]);
	auto C = to!ulong(tokens[2]);

	ulong ans = min(A + B + 1, C) + B;
	writeln(ans);
	stdout.flush();
	/*}catch (Throwable e)
	{
	writeln(e.toString());
	}
	readln();*/
}
