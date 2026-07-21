import std.algorithm, std.container, std.conv, std.math, std.range, std.typecons, std.stdio, std.string;

auto rdsp(){return readln.splitter;}
void pick(R,T)(ref R r,ref T t){t=r.front.to!T;r.popFront;}
void readV(T...)(ref T t){auto r=rdsp;foreach(ref v;t)pick(r,v);}
void readA(T)(size_t n,ref T[]t){t=new T[](n);auto r=rdsp;foreach(ref v;t)pick(r,v);}

void main()
{
  int n; readV(n);
  long[] a; readA(n, a);

  auto b = a.map!"a>0".array;
  foreach (i; 0..n-1)
    if (!b[i]) {
      b[i] = !b[i];
      b[i+1] = !b[i+1];
    }

  auto c = a.map!abs.array;
  if (b[$-1])
    writeln(c.sum);
  else
    writeln(c.sum-c.reduce!min*2);
}
