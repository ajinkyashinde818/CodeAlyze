import std.algorithm;
import std.array;
import std.conv;
import std.math;
import std.range;
import std.stdio;
import std.string;
import std.traits;

pure nothrow @nogc
T gcdext(T) (T a, T b, ref T x, ref T y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  T res = gcdext (b, a % b, y, x);
  y -= x * (a / b);
  return res;
}

struct IntM(int q = 1_000_000_007) {
  alias N = IntM!q;
  private:
  int v;
  pure nothrow @nogc
  static int from(T) (const T m) if (isIntegral!T) {
    int v = m % q;
    static if (isSigned!T) {
      if (v < 0) {
        v += q;
      }
    }
    return v;
  }
  public:
  pure nothrow @nogc
  this(T) (const T m) if (isIntegral!T) {
    v = from!T (m);
  }
  pure nothrow @nogc
  N opAssign(T) (const T m) if (isIntegral!T) {
    v = from!T (m);
    return this;
  }
  pure nothrow @nogc
  N opUnary (string op : "-")() const {
    return N (-v);
  }
  pure nothrow @nogc
  ref N opUnary (string op : "++")() {
    if (++v >= q) {
      v -= q;
    }
    return this;
  }
  pure nothrow @nogc
  ref N opUnary (string op : "--")() {
    if (--v < 0) {
      v += q;
    }
    return this;
  }
  pure nothrow @nogc
  ref N opOpAssign (string op : "+")(in N rhs) {
    v = (v + rhs.v) % q;
    return this;
  }
  pure nothrow @nogc
  ref N opOpAssign (string op : "-")(in N rhs) {
    v = (v - rhs.v + q) % q;
    return this;
  }
  pure nothrow @nogc
  ref N opOpAssign (string op : "*")(in N rhs) {
    v = (v.to!(long) * rhs.v) % q;
    return this;
  }
  pure nothrow @nogc
  ref N opOpAssign (string op : "/")(in N rhs) {
    return this *= rhs.inversion ();
  }
  pure nothrow @nogc
  ref N opOpAssign (string op)(in int rhs) if (op == "+" || op == "-" || op == "*" || op == "/") {
    mixin ("return this " ~ op ~ "= N(rhs);");
  }
  pure nothrow @nogc
  N opBinary (string op)(in N rhs) const if (op == "+" || op == "-" || op == "*" || op == "/") {
    N t = this;
    mixin ("t " ~ op ~ "= rhs;");
    return t;
  }
  pure nothrow @nogc
  N opBinary(string op,T)(const T rhs) const if (isIntegral!T && (op == "+" || op == "-" || op == "*" || op == "/")) {
    mixin ("return this " ~ op ~ " N(rhs);");
  }
  pure nothrow @nogc
  N opBinaryRight(string op,T)(const T rhs) const if (isIntegral!T && (op == "+" || op == "*")) {
    mixin ("return this " ~ op ~ " N(rhs);");
  }
  pure nothrow @nogc
  N inversion () const {
    int x, y;
    immutable g = gcdext!int (v, q, x, y);
    assert (g == 1);
    return N (x);
  }
  pure nothrow @nogc
  N opBinary (string op : "^^")(in ulong rhs) const {
    return genericPower! ("a * b", N, ulong) (this, rhs);
  }
  pure nothrow @nogc
  int opCast(T : int)() const { return v; }
  pure nothrow @nogc
  int opCmp (const N rhs) const {
    if (v < rhs.v) {
      return -1;
    }
    if (v > rhs.v) {
      return 1;
    }
    return 0;
  }
  pure nothrow
  string toString() const { return v.text; }
  //a ^ x = this (mod q)
}

alias N = IntM!1_000_000_007;

int test (in int[] a, in int[] d) {
  immutable int n = d.length.to!int;
  auto f = new N[n+10];
  auto g = new N[n+10]; 
  f[0] = N (1);
  foreach (i; 1 .. n + 10) {
    f[i] = f[i-1] * N (i);
    g[i] = f[i].inversion ();
  }
  auto h = new N[n+1];
  foreach (l; 0 .. n + 1) {
    h[l] = f[l+1] * g[l+2];
  }
  foreach (l; 1 .. n + 1) {
    h[l] += h[l-1];
  }
  N res = 0;
  foreach (i; 0 .. d.length) {
    N delta;
    delta.v = d[i];
    N x = 1;
    //N x = f[n];
    /*
    foreach (l; 0 .. i) {
      x += f[l+1] * g[l+2];
    }
    */
    if (i > 0) {
      x += h[i-1];
    }
    res += delta * x;
  }
  res *= f[n];
  return res.to!int;
}

void main() {
  int n;
  readf (" %d", &n);
  auto x = new int[n];
  foreach (i; 0 .. n) {
    readf (" %d", &x[i]);
  }
  auto d = new int[n-1];
  foreach (i; 1 .. n) {
    d[i-1] = x[i] - x[i-1];
  }
  writeln (test (x, d));
}
