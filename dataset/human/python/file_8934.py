import std.algorithm, std.container, std.conv, std.math, std.range, std.typecons, std.stdio, std.string;

auto rdsp(){return readln.splitter;}
void pick(R,T)(ref R r,ref T t){t=r.front.to!T;r.popFront;}
void readV(T...)(ref T t){auto r=rdsp;foreach(ref v;t)pick(r,v);}

const e = ["dream", "dreamer", "erase", "eraser"];

void main()
{
  string s; readV(s);

 loop: while (!s.empty) {
    foreach (ei; e) {
      if (s.endsWith(ei)) {
        s = s[0..$-ei.length];
        continue loop;
      }
    }

    writeln("NO");
    return;
  }

  writeln("YES");
}
