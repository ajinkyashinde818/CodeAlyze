// url: http://tenka1-2017-beginner.contest.atcoder.jp/tasks/tenka1_2017_a

import std.algorithm, std.conv, std.range, std.stdio, std.string;

void main()
{
  auto rd1 = readln.split, n = rd1[0].to!size_t, k = rd1[1].to!long;

  struct AB { long a, b; }
  auto ab = new AB[](n);

  foreach (i; 0..n) {
    auto rd2 = readln.splitter;
    auto a = rd2.front.to!long; rd2.popFront();
    auto b = rd2.front.to!long;
    ab[i] = AB(a, b);
  }
  ab = ab.filter!(abi => abi.a <= k).array;

  long calc(ptrdiff_t b, AB[] c)
  {
    if (b == -1) return c.map!"a.b".sum;

    if (k.bitTest(b)) {
      auto r1 = calc(b-1, c);
      auto r2 = c.filter!(ci => !ci.a.bitTest(b)).map!"a.b".sum;
      return max(r1, r2);
    } else {
      return calc(b-1, c.filter!(ci => !ci.a.bitTest(b)).array);
    }
  }

  if (k == 0)
    writeln(ab.filter!(abi => abi.a == 0).map!"a.b".sum);
  else
    writeln(calc(k.bsr, ab));
}

pragma(inline) {
  pure bool bitTest(T)(T n, size_t i) { return (n & (T(1) << i)) != 0; }
  pure T bitSet(T)(T n, size_t i) { return n | (T(1) << i); }
  pure T bitReset(T)(T n, size_t i) { return n & ~(T(1) << i); }
  pure T bitComp(T)(T n, size_t i) { return n ^ (T(1) << i); }

  import core.bitop;
  pure int bsf(T)(T n) { return core.bitop.bsf(ulong(n)); }
  pure int bsr(T)(T n) { return core.bitop.bsr(ulong(n)); }
  pure int popcnt(T)(T n) { return core.bitop.popcnt(ulong(n)); }
}
