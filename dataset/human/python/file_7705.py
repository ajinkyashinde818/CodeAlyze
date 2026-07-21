import std.algorithm, std.container, std.conv, std.math, std.range, std.typecons, std.stdio, std.string;

auto rdsp(){return readln.splitter;}
void pick(R,T)(ref R r,ref T t){t=r.front.to!T;r.popFront;}
void readV(T...)(ref T t){auto r=rdsp;foreach(ref v;t)pick(r,v);}

void main()
{
  int x; readV(x);
  writeln(x < 1200 ? "ABC" : "ARC");
}
