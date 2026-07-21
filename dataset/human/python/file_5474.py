import std.algorithm, std.container, std.conv, std.math, std.range, std.typecons, std.stdio, std.string;

void readV(T...)(ref T t){auto r=readln.splitter;foreach(ref v;t){v=r.front.to!(typeof(v));r.popFront;}}

void main()
{
  string x, y; readV(x, y);
  writeln(x > y ? ">" : x < y ? "<" : "=");
}
