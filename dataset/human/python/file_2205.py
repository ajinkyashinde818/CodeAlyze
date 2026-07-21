import std.algorithm, std.container, std.conv, std.math, std.range, std.typecons, std.stdio, std.string;

auto rdsp(){return readln.splitter;}
void pick(R,T)(ref R r,ref T t){t=r.front.to!T;r.popFront;}
void readV(T...)(ref T t){auto r=rdsp;foreach(ref v;t)pick(r,v);}
void readC(T...)(size_t n,ref T t){foreach(ref v;t)v=new typeof(v)(n);foreach(i;0..n){auto r=rdsp;foreach(ref v;t)pick(r,v[i]);}}

void main()
{
  int d, g; readV(d, g); g /= 100;
  int[] p, c; readC(d, p, c); c[] /= 100;
  
  auto m = d.iota.map!(i => (i+1)*p[i]).sum + c.sum;
  auto dp = new int[][](d+1, m+1), inf = 10^^9;
  foreach (dpi; dp) dpi[] = inf;
  dp[0][0] = 0;

  foreach (i; 0..d) {
    auto s = i+1;
    foreach (j; 0..m+1) {
      foreach (k; 0..p[i])
        if (j-k*s >= 0)
          dp[i+1][j] = min(dp[i+1][j], dp[i][j-k*s]+k);
      if (j-(p[i]*s+c[i]) >= 0)
        dp[i+1][j] = min(dp[i+1][j], dp[i][j-(p[i]*s+c[i])]+p[i]);
    }
  }

  writeln(dp[d][g..$].reduce!min);
}
