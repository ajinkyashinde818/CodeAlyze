import std.functional,
       std.algorithm,
       std.typecons,
       std.bigint,
       std.string,
       std.traits,
       std.array,
       std.range,
       std.stdio,
       std.conv,
       std.math;

T read_num(T)() { return readln.chomp.to!T; }
T[] read_nums(T)() { return readln.chomp.split.to!(T[]); }

enum INF = 1L << 30;

T max(T)(T a, T b) { return a < b ? b : a; }
T abs(T)(T x) { return x < 0 ? -x : x; }
bool chmax(T)(ref T a, T b) {
  if (a < b) {
    a = b;
    return true;
  } else {
    return false;
  }
}
bool chmin(T)(ref T a, T b) {
  if (a > b) {
    a = b;
    return true;
  } else {
    return false;
  }
}
void main() {
  long N = read_num!long;
  long[] A = read_nums!long;
  long[] negs, poss;
  long ans;

  A.sort!"a<b";
  foreach (a; A) {
    if (a < 0) {
      negs ~= a;
    } else {
      poss ~= a;
    }
  }

  if (negs.length & 1) {
    long l = -INF;
    long r = INF;
    foreach (x; negs) {
      chmax(l, x);
    }
    foreach (x; poss) {
      chmin(r, x);
    }
    ans -= min(abs(l), abs(r)) * 2;
  }
    foreach (a; A) {
      ans += abs(a);
    }

  writeln(ans);
}
