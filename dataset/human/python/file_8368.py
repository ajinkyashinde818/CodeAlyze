import std.stdio;
import std.conv;
import std.string;
import std.algorithm;

void main() {
  int k, n;
  readf("%d %d\n", &k, &n);
  auto a = readln.chomp.split.map!(to!int);
  int distmax = 0;
  for(int i=0; i<n-1; i++) {
    auto dist = a[i+1] - a[i];
    if(dist > distmax) distmax = dist;
  }
  auto dist = a[0] + (k - a[$-1]);
  if(dist > distmax) distmax = dist;
  writeln(k - distmax);
}
