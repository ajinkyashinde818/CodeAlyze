import std.algorithm, std.container, std.conv, std.math, std.range, std.typecons, std.stdio, std.string;

auto rdsp(){return readln.splitter;}
void pick(R,T)(ref R r,ref T t){t=r.front.to!T;r.popFront;}
void readV(T...)(ref T t){auto r=rdsp;foreach(ref v;t)pick(r,v);}

void main()
{
  int n, m; readV(n, m);

  auto c = new int[](n+1);
  foreach (_; 0..m) {
    int a, b; readV(a, b);
    if (a == 1) c[b]++;
    if (b == n) c[a]++;
  }

  writeln(c.canFind(2) ? "POSSIBLE" : "IMPOSSIBLE");
}
