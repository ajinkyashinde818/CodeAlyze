import sequtils, strutils

let
  nks = stdin.readline.split.map(parseInt)
  (n, k, s) = (nks[0], nks[1], nks[2])
  dummy = if s > 2: s-1 else: s+1
  xs = concat(s.repeat(k), dummy.repeat(n-k))

echo xs.mapIt($it).join(" ")
