import std.algorithm, std.container, std.conv, std.math, std.range, std.typecons, std.stdio, std.string;

auto rdsp(){return readln.splitter;}
void pick(R,T)(ref R r,ref T t){t=r.front.to!T;r.popFront;}
void readV(T...)(ref T t){auto r=rdsp;foreach(ref v;t)pick(r,v);}
void readC(T...)(size_t n,ref T t){foreach(ref v;t)v=new typeof(v)(n);foreach(i;0..n){auto r=rdsp;foreach(ref v;t)pick(r,v[i]);}}

void main()
{
  int n, m; readV(n, m);
  string[] a; readC(n, a);
  string[] b; readC(m, b);

  foreach (y; 0..n-m+1)
    foreach (x; 0..n-m+1)
      if (a[y..y+m].map!(ai => ai[x..x+m]).array == b) {
        writeln("Yes");
        return;
      }

  writeln("No");
}
