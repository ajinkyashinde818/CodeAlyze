module app;

import core.bitop;

import std.algorithm;
import std.array;
import std.bigint;
import std.container.rbtree;
import std.conv;
import std.stdio;
import std.string;
import std.traits;

struct Input
{
    string s;
    int q;
    Query[] queries;
}

enum QueryType
{
    reverse,
    prepend,
    append,
}

struct Query
{
    QueryType type;
    char c;
}

void parseInput(T)(out Input input, T file)
{
	with (file) with (input)
	{
        s = readln().strip();
        q = readln().strip().to!int;
        queries.length = q;
        foreach (i; 0..q)
        {
            Query query;
		    auto ar = readln().strip().split().array();
            auto t = ar[0];
            if (t == "1")
            {
                query.type = QueryType.reverse;
            }
            else
            {
                auto f = ar[1];
                if (f == "1")
                {
                    query.type = QueryType.prepend;
                }
                else
                {
                    query.type = QueryType.append;
                }
                query.c = ar[2][0];
            }
            queries[i] = query;
        }
	}
}

auto main2(Input* input)
{
	with (input)
	{
        char[200000] pre;
        int preLength = 0;
        char[200000] post;
        int postLength = 0;
        bool reversed = false;

        foreach (query; queries)
        {
            final switch (query.type) with (QueryType)
            {
                case reverse:
                    reversed = !reversed;
                    break;
                case prepend:
                    if (!reversed)
                        pre[preLength++] = query.c;
                    else
                        post[postLength++] = query.c;
                    break;
                case append:
                    if (reversed)
                        pre[preLength++] = query.c;
                    else
                        post[postLength++] = query.c;
                    break;
            }
        }

        if (!reversed)
        {
            for (int i = preLength - 1; i >= 0; i--)
            {
                write(pre[i]);
            }
            write(s);
            for (int i = 0; i < postLength; i++)
            {
                write(post[i]);
            }
        }
        else
        {
            for (int i = postLength - 1; i >= 0; i--)
            {
                write(post[i]);
            }
            foreach_reverse (c; s)
                write(c);
            for (int i = 0; i < preLength; i++)
            {
                write(pre[i]);
            }
        }
	}
}

alias retType = ReturnType!main2;

void printResult(T)(T result)
{
	static if (isFloatingPoint!T) writefln("%f", result);
	else writeln(result);
}

void main()
{
	Input input = void;
	parseInput(input, stdin);
	static if (is(retType == void))
		main2(&input);
	else
	{
		auto result = main2(&input);
		printResult(result);
	}
}
