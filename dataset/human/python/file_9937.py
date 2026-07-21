module app;

import core.bitop;

import std.algorithm;
import std.array;
import std.bigint;
import std.conv;
import std.stdio;
import std.string;

struct Input
{
	ulong a, b;
}

void parseInput(T)(out Input input, T file)
{
	with (file) with (input)
	{
		auto array = readln().strip().split();
		a = array[0].to!ulong;
		b = array[1].to!ulong;
	}
}

struct Output
{
}

auto main2(Input* input)
{
	return lcm(input.a, input.b);
}

unittest { writeln("begin unittest"); }

unittest // example1
{
	string example =
`2 3`;
	Input input = void;
	parseExample(input, example);
	auto result = main2(&input);
	writeln(result);
	assert(result == 6);
}

unittest // example2
{
	string example =
`123 456`;
	Input input = void;
	parseExample(input, example);
	auto result = main2(&input);
	writeln(result);
	assert(result == 18696);
}

unittest // example3
{
	string example =
        `100000 99999`;
	Input input = void;
	parseExample(input, example);
	auto result = main2(&input);
	writeln(result);
	assert(result == 9999900000);
}

unittest { writeln("end unittest"); }

void parseExample(out Input input, string example)
{
	struct Adapter
	{
		string[] _lines;
		this(string input) { _lines = input.splitLines(); }
		string readln() { auto line = _lines[0]; _lines = _lines[1..$]; return line; }
	}
	parseInput(input, Adapter(example));
}

void main()
{
	Input input = void;
	parseInput(input, stdin);
	auto result = main2(&input);
	writeln(result);
}

T lcm(T)(T i1, T i2)
{
	return i1 / gcm(i1, i2) * i2;
}

T gcm(T)(T i1, T i2)
{
	T large = i1 < i2 ? i2 : i1;
	T small = i1 < i2 ? i1 : i2;

	while (small != 0)
	{
		T q = large % small;

		large = small;
		small = q;
	}

	return large;
}
