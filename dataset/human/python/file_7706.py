import std.stdio, std.conv, std.string, std.array, std.math, std.regex, std.range, std.ascii, std.numeric, std.random;
import std.typecons, std.functional, std.traits,std.concurrency;
import std.algorithm, std.container;
import core.bitop, core.time, core.memory;
import std.bitmanip;
import std.regex;

enum INF = long.max/3;
enum MOD = 10L^^9+7;

//辞書順順列はiota(1,N),nextPermituionを使う


void end(T)(T v)
if(isIntegral!T||isSomeString!T||isSomeChar!T)
{
    import core.stdc.stdlib;
    writeln(v);
    exit(0);
}

T[] scanArray(T = long)()
{
    static char[] scanBuf;
    readln(scanBuf);
    return scanBuf.split.to!(T[]);
}

dchar scanChar()
{
    int c = ' ';
    while (isWhite(c) && c != -1)
    {
        c = getchar;
    }
    return cast(dchar)c;
}

T scanElem(T = long)()
{
    import core.stdc.stdlib;
    static auto scanBuf = appender!(char[])([]);

    scanBuf.clear;

    int c = ' ';
    while (isWhite(c) && c != -1)
    {
        c = getchar;
    }
    while (!isWhite(c) && c != -1)
    {
        scanBuf ~= cast(char) c;
        c = getchar;
    }
    return scanBuf.data.to!T;
}

dchar[] scanString(){
    return scanElem!(dchar[]);
}


void main()
{
  auto n=scanElem;
  if(n>=1200)end("ARC");end("ABC");
}
