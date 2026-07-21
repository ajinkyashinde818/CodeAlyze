/* imports all std modules {{{*/
import
  std.algorithm,
  std.array,
  std.ascii,
  std.base64,
  std.bigint,
  std.bitmanip,
  std.compiler,
  std.complex,
  std.concurrency,
  std.container,
  std.conv,
  std.csv,
  std.datetime,
  std.demangle,
  std.encoding,
  std.exception,
  std.file,
  std.format,
  std.functional,
  std.getopt,
  std.json,
  std.math,
  std.mathspecial,
  std.meta,
  std.mmfile,
  std.net.curl,
  std.net.isemail,
  std.numeric,
  std.parallelism,
  std.path,
  std.process,
  std.random,
  std.range,
  std.regex,
  std.signals,
  std.socket,
  std.stdint,
  std.stdio,
  std.string,
  std.system,
  std.traits,
  std.typecons,
  std.uni,
  std.uri,
  std.utf,
  std.uuid,
  std.variant,
  std.zip,
  std.zlib;
/*}}}*/

/+:---test
3
3 1 2
2 5 4
3 6
---+/
/+---test
4
2 3 4 1
13 5 8 24
45 9 15
---+/
/+---test
2
1 2
50 50
50
---+/

void main(string[] args) {
  readln;

  const A = readln.split.map!(x => x.to!long-1).array;
  const B = readln.split.map!(to!long).array;
  const C = readln.split.map!(to!long).array;

  const N = A.length;

  long ans = B[A[0]];
  foreach (i; 1..N) {
    ans += B[A[i]];

    if (A[i-1]+1 == A[i]) {
      ans += C[A[i-1]];
    }
  }
  ans.writeln;
}
