module app;

import core.bitop;

import std.algorithm;
import std.array;
import std.bigint;
import std.conv;
import std.stdio;
import std.string;
import std.traits;

struct Input
{
	int n, r;
}

void parseInput(T)(out Input input, T file)
{
	with (file) with (input)
	{
		auto ar = readln().strip().split().map!(to!int).array();
		n = ar[0].to!int;
		r = ar[1].to!int;
	}
}

auto main2(Input* input)
{
	with (input)
	{
        if (n >= 10)
            return r;
        else
            return r + 100 * (10 - n);
	}
}

alias retType = ReturnType!main2;
static if (!is(retType == void))
{
	unittest { writeln("begin unittest"); }
	auto _placeholder_ = ReturnType!main2.init;

	unittest // example1
	{
		string example =
`2 2919`;
		if (example.empty) return;
		Input input = void;
		parseExample(input, example);
		auto result = main2(&input);
		printResult(result);
		assert(result == 3719);
	}

	unittest // example2
	{
		string example =
`22 3051`;
		if (example.empty) return;
		Input input = void;
		parseExample(input, example);
		auto result = main2(&input);
		printResult(result);
		assert(result == 3051);
	}

	unittest // example3
	{
		string example =
``;
		if (example.empty) return;
		Input input = void;
		parseExample(input, example);
		auto result = main2(&input);
		printResult(result);
		assert(result == _placeholder_);
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
}

void printResult(T)(T result)
{
	static if (isFloatingPoint!T) writefln("%f", result);
	else writeln(result);
}

void main()
{
	Input input = void;
	parseInput(input, stdin);
	alias retType = ReturnType!main2;
	static if (is(retType == void))
		main2(&input);
	else
	{
		auto result = main2(&input);
		printResult(result);
	}
}
