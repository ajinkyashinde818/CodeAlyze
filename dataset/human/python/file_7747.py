import sequtils, strutils, algorithm, math, sets, tables
when NimMajor == 0 and NimMinor <= 18: import future else: import sugar

var (N,K,S) = (let t = stdin.readline.split.map(parseInt);(t[0],t[1],t[2]))
var A = newSeqWith(N,0)
var dum = 10^9
if S == 10^9:
  dum = 10^9-1

for i in 0..<N:
  if i<K:
    A[i] = S
  else:
    A[i] = dum

echo(A.mapIt($it).join(" "))
