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

/+---test
2 3
---+/

void main(string[] args) {
  long A, B;
  readf(" %d %d ", &A, &B);

  (A*B/gcd(A, B)).writeln;
}
