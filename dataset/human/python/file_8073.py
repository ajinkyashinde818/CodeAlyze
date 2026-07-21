import std.algorithm, std.container, std.conv, std.math, std.range, std.typecons, std.stdio, std.string;

auto rdsp(){return readln.splitter;}
void pick(R,T)(ref R r,ref T t){t=r.front.to!T;r.popFront;}
void readV(T...)(ref T t){auto r=rdsp;foreach(ref v;t)pick(r,v);}

void main()
{
  int k, s; readV(k, s);

  auto ans = 0;
  foreach (x; 0..k+1)
    foreach (y; 0..k+1) {
      auto z = s-x-y;
      if (z >= 0 && z <= k) ++ans;
    }

  writeln(ans);
}
