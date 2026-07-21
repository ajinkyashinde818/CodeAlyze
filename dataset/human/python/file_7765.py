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
4 2 3
---+/
/+---test
5 3 100
---+/

void main(string[] args) {
  long N, K, S;
  readf(" %d %d %d ", &N, &K, &S);

  auto S_ = S+1;
  if (S_ > 10000) S_ -= 2;

  foreach (i; 0..K) {
    S.write;
    if (i != N-1) " ".write;
  }
  foreach (i; K..N) {
    S_.write;
    if (i != N-1) " ".write;
  }
  writeln;
}
