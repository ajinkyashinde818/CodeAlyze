module app;

import std.array;
import std.algorithm;
import std.conv;
import std.stdio;
import std.string;

void main()
{
	auto input = parseInput();
    writefln("%d", main2(input));
}

auto main2(Input input)
{
    int count = 0;
    int lastIndex = -2;
    for (int i = 0; i < input.n; i++)
    {
        auto index = input.a[i] - 1;
        count += input.b[index];
        if (lastIndex + 1 == index)
        {
            count += input.c[lastIndex];
        }
        lastIndex = index;
    }
    return count;
}

unittest
{
    Input input = {3,[3,1,2],[2,5,4],[3,6]};
    auto result = main2(input);
    writefln("%d", result);
    assert(result == 14);
}

unittest
{
    Input input = {4,[2,3,4,1],[13,5,8,24],[45,9,15]};
    auto result = main2(input);
    writefln("%d", result);
    assert(result == 74);
}

struct Input
{
	int n;
    int[] a;
    int[] b;
    int[] c;
}

auto parseInput()
{
	Input input = void;
	input.n = readln().strip().to!int;
    input.a = readln().strip().split().map!(a=>a.to!int).array();
    input.b = readln().strip().split().map!(a=>a.to!int).array();
    input.c = readln().strip().split().map!(a=>a.to!int).array();
	return input;
}
